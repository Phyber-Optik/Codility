#include<bits/stdc++.h>
using namespace std;

int dp[501][5001];

class Solution {
public:

    int helper(int cur_pos, int sum, int N, int S) {
        if(cur_pos == N) {
            return sum == S;
        }
        if(dp[cur_pos][sum] != -1) return dp[cur_pos][sum];
        
        int res = 0;
        for(int i = 0; i < 10; i++) {
            if(i == 0 && cur_pos == 0) continue;
            if(sum + i <= S)
                res = (res + helper(cur_pos + 1, sum + i, N, S)) % 1000000007;
        }
        return dp[cur_pos][sum] = res;
    }

    int solve(int A, int B) {
        memset(dp, -1, sizeof dp);
        return helper(0, 0, A, B);
    }
};

int main() {
    cout<<Solution().solve(75, 22)<<endl;
}