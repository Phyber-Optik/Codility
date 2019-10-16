#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int go(int pos, string &s, unordered_map<int, int> &dp) {
        if(pos == s.size()) return 1;
        if(dp.find(pos) != dp.end()) return dp[pos];
        int ret = 0;
        int cur = 0;
        for(int i = 0; i < 2; i++) {
            if(pos + i < s.size()) {
                cur = cur * 10 + s[pos + i];
                if(cur == 0) break;
                if(cur < 27)
                    ret += go(pos + i + 1, s, dp);
            }
        }
        return dp[pos] = ret;
    }
    int numDecodings(string s) {
        unordered_map<int, int>dp;
        return go(0, s, dp);
    }
};