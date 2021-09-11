//
// Created by ednow on 2021/9/11.
//

#define CASEID 1003

#ifdef CASEID
#define MAIN PTA1003
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "numeric"
#include "algorithm"
#include "set"

using namespace std;

void dfs(vector<set<int>> &graph, int start, int&spotsNum, vector<bool> &isVisited ){
    isVisited[start] = true;
    spotsNum++;
    for (auto & neighbor:graph[start]) {
        if (!isVisited[neighbor]) {
            dfs(graph, neighbor, spotsNum, isVisited);
            return;
        }

    }
}

struct Starter {
    int idx{};
    int spotNum{};
};

int
MAIN(){
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;
    vector<set<int>> graph(nodeNum+1);
    while (edgeNum--) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<Starter> spotsNumByIdx(nodeNum+1);
    for (int i = 0; i < nodeNum+1; ++i) {
        spotsNumByIdx[i].idx = i;
    }

    for (int i = 1; i < nodeNum+1; ++i) {
        vector<bool> isVisited(nodeNum+1, false);
        int spotsNum{};
        dfs(graph, i, spotsNum, isVisited);
        spotsNumByIdx[i].spotNum = spotsNum;
    }

    sort(spotsNumByIdx.begin(), spotsNumByIdx.end(), [](auto &a, auto &b) {
        if (a.spotNum != b.spotNum) return a.spotNum > b.spotNum;
        return a.idx < b.idx;
    });

    cout << (*spotsNumByIdx.begin()).idx << " " << (*spotsNumByIdx.begin()).spotNum << endl;
    return 0;
}

#ifdef CASEID

#include "ednow/utils.h"

TEST(pta,CASEID){
    DO_TEST(CASEID)
}

#endif