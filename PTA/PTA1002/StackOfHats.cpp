//
// Created by ednow on 2021/9/11.
//

#define CASEID 1002

#ifdef CASEID
#define MAIN PTA1002
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "numeric"
#include "algorithm"

using namespace std;

struct Hat{
    // 0代表要被第一个拿走
    int storeIdx{};
    // 这个帽子是大小排第几的
    int sortIdx{};
    // 帽子的大小
    int size{};
};

struct People {
    // 这个人的编号
    int idx{};
    // 这个人的体重
    int weight{};
};

int
MAIN(){
    int N;
    cin >> N;
    vector<Hat> hats(N);
    vector<People> peoples(N);
    while (N--) {
        cin >> hats[N].size;
        hats[N].storeIdx = N + 1;
    }

    for (int i = 0; i < peoples.size(); ++i) {
        cin >> peoples[i].weight;
        peoples[i].idx = i + 1;
    }

    sort(hats.begin(), hats.end(), [](auto &a, auto&b) {
        return a.size > b.size;
    });

    // 帽子匹配的人的下标
    for (int i = 0; i < hats.size(); ++i) {
        hats[i].sortIdx = i;
    }

    // 按照拿出的顺序排好
    sort(hats.begin(), hats.end(), [](auto &a, auto&b) {
        return a.storeIdx < b.storeIdx;
    });

    // 按照体重顺序排好
    sort(peoples.begin(), peoples.end(), [](auto &a, auto&b) {
        return a.weight > b.weight;
    });

    auto hatIter = hats.begin();
    cout << peoples[(*hatIter++).sortIdx].idx;
    while (hatIter != hats.end()) {
        cout << " " << peoples[(*hatIter++).sortIdx].idx;
    }
    cout << endl;
    return 0;
}

#ifdef CASEID

#include "ednow/utils.h"

TEST(pta,CASEID){
    DO_TEST(CASEID)
}

#endif