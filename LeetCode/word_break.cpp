#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string>mp;
    unordered_map<int, bool>dp;
    
    bool go(int cur, string &s)
    {
        if(cur == s.size()) return true;
        if(dp.find(cur) != dp.end()) return dp[cur];
        string str = "";
        bool ret = false;
        for(int i = cur; i < s.size(); i++)
        {
            str += s[i];
            if(mp.find(str) != mp.end())
                ret |= go(i + 1, s);
        }
        return dp[cur] = ret;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        mp.clear();
        for(string s: wordDict) mp.insert(s);
        return go(0, s);
    }
};