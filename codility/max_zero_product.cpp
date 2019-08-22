#include<bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<pii>div_counts;
int dp[100001][39][3];

int go(int i, int s, int c) {
    if(i >= div_counts.size()) return -100000000;
    if(dp[i][s][c] != -1) return dp[i][s][c];
    if(c==1) {
        if(div_counts[i].second >= s)
            return dp[i][s][c] = max(div_counts[i].first, go(i + 1, s, c));
        return dp[i][s][c] = go(i + 1, s, c);
    }
    return dp[i][s][c] = max(div_counts[i].first + go(i + 1, max(s - div_counts[i].second, 0), c - 1), go(i + 1, s, c));
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    for(int x : A) {
        int twos, fives;
        twos = fives = 0;
        while(x%2 == 0) {
            x /= 2;
            twos++;
        }
        while(x%5 == 0) {
            x /= 5;
            fives++;
        }
        div_counts.push_back(pii(twos, fives));
    } 
    
    int L = 0, R = 39, ans = 0;
    memset(dp, -1, sizeof(dp));
    while(L <= R) {
        int mid = (L + R) / 2;
        int res = go(0, mid, 3);
        if(res >= mid) {
            ans = max(ans, mid);
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }
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