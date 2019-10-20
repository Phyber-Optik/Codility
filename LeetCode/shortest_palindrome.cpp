#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check_pal(int l, int r, string &s) {
        for(int i = 0; i < (r - l + 1) / 2; i++) {
            if(s[l + i] != s[r - i]) return false;
        }
        return true;
    }

    string shortestPalindrome(string s) {
        string prefix;
        for(int i = s.size() - 1, j = 1; i >= 0; i--, j++) {
            if(check_pal(0, i, s)) {
                prefix = s.substr(i, j);
            }
        }
        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};