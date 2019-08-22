#include<bits/stdc++.h>


using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, bool>unique_from_beg, unique_from_end;
    int len = A.size();
    int unique_cnt_beg[len];
    int unique_cnt_end[len];
    memset(unique_cnt_beg, 0, sizeof(unique_cnt_beg));
    memset(unique_cnt_end, 0, sizeof(unique_cnt_end));
    int unique_cnt = 0;
    for(int i = 0; i < len; i++) {
        if(!unique_from_beg[A[i]]) {
            unique_from_beg[A[i]] = true;
            unique_cnt++;
        }
        unique_cnt_beg[i] = unique_cnt;
    }
    unique_cnt = 0;
    for(int i = len - 1; i >= 0; i--) {
        if(!unique_from_end[A[i]]) {
            unique_from_end[A[i]] = true;
            unique_cnt++;
        }
        unique_cnt_end[i] = unique_cnt;
    }
    unordered_map<int, int>last_inst;
    long long ans = 0;
    for(int i = 1; i < len - 1; i++) {
        long long unique_before_this;
        if (last_inst.find(A[i]) != last_inst.end()) {
            unique_before_this = unique_cnt_beg[i-1] - unique_cnt_beg[last_inst[A[i]]-1];
        }
        else unique_before_this = unique_cnt_beg[i-1];
        last_inst[A[i]] = i;
        long long unique_after_this = unique_cnt_end[i+1];
        ans = (ans + unique_before_this * unique_after_this) % 1000000007LL;
    }
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);    
    int n;
    vector<int>A;
    while(cin>>n) {
        A.push_back(n);
    }
    cout<<solution(A)<<endl;
    return 0;
}