#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int apply_backspaces(string &S) {
        int L = 0, R = 0;
        while(R < S.size()) {
            if(S[R] == '#') {
                if(L > 0) L--;
            }
            else {
                swap(S[L++], S[R]);
            }
            R++;
        }
        return L;
    }
    bool backspaceCompare(string S, string T) {
        int SL = apply_backspaces(S);
        int TL = apply_backspaces(T);
        if(SL != TL) return false;
        for(int i = 0; i < SL; i++) {
            if(S[i] != T[i]) return false;
        }

        return true;
    }
};

int main() {
    Solution().backspaceCompare("ab#c", "ad#c");
    return 0;
}