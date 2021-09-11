//
// Created by ednow on 2021/9/11.
//

#define CASEID 1001

#ifdef CASEID
#define MAIN PTA1001
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "numeric"

using namespace std;

struct Array {
    int start{};
    int size{};
    int startIdx{};
};

int
MAIN(){
    int N, K;
    cin >> N >> K;
    vector<Array> arrays(N);
    int maxSize{};
    for (int i = 0; i < N; ++i) {
        cin >> arrays[i].start;
        cin >> arrays[i].size;
        arrays[i].startIdx = maxSize;
        maxSize += arrays[i].size;
    }
    vector<int> arrayHasUsed(N, 0);
    while (K--) {
        int queryIdx{};
        cin >> queryIdx;
        if (queryIdx > maxSize-1) {
            cout << "Illegal Access" << endl;
            continue;
        }
        bool isFind{false};
        int arrayIdx{};
        for (int i = 0; i < N; ++i) {
            if (queryIdx >= arrays[i].startIdx  and queryIdx < arrays[i + 1].startIdx) {
                isFind = true;
                arrayIdx = i;
                break;
            }
        }
        // 没找到的话就是在最后一个array里面
        if (isFind) {
            arrayHasUsed[arrayIdx] = true;
            cout << (queryIdx - arrays[arrayIdx].startIdx)*4 + arrays[arrayIdx].start << endl;
        } else {
            cout << (queryIdx - arrays[arrays.size()-1].startIdx)*4 + arrays[arrayIdx].start << endl;
            arrayHasUsed[arrays.size()-1] = true;
        }
    }
    cout << accumulate(arrayHasUsed.begin(), arrayHasUsed.end(),0, plus<>()) << endl;
    return 0;
}

#ifdef CASEID

#include "ednow/utils.h"

TEST(pta,CASEID){
    DO_TEST(CASEID)
}

#endif