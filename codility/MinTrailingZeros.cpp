#include<bits/stdc++.h>

#define pii pair<int, int>
#define MAX 501
#define MAX_ 10000000

using namespace std;

vector<vector<pii>> fact_cnt;
int n;
bool vis[MAX][MAX];
pii dp[MAX][MAX];

pii go(int r, int c) {
    if(r >= n || c >= n) return pii(MAX_, MAX_);
    if(r == n - 1 && c == n - 1) return pii(fact_cnt[r][c].first, fact_cnt[r][c].second);

    if(vis[r][c]) return dp[r][c];
    vis[r][c] = true;
    
    pii ret_right = go(r, c + 1);
    pii ret_down = go(r + 1, c);
    int right_min = min(ret_right.first + fact_cnt[r][c].first, ret_right.second + fact_cnt[r][c].second);
    int down_min = min(ret_down.first + fact_cnt[r][c].first, ret_down.second + fact_cnt[r][c].second);

    if(right_min < down_min) return dp[r][c] = pii(ret_right.first + fact_cnt[r][c].first, ret_right.second + fact_cnt[r][c].second);
    else return dp[r][c] = pii(ret_down.first + fact_cnt[r][c].first, ret_down.second + fact_cnt[r][c].second);
}

int solution(vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = MAX_;
    for(vector<int>x: A) {
        vector<pii>temp;
        for(int y : x) {
            if(y == 0) temp.push_back(pii(1, 1));
            else {
                int two = 0, five = 0;
                while(y && y % 2 == 0) {
                    y /= 2;
                    two++;
                }
                while(y && y % 5 == 0) {
                    y /= 5;
                    five++;
                }
                temp.push_back(pii(two, five));
            }
        }
        fact_cnt.push_back(temp);
    }
    n = A.size();
    memset(vis, false, sizeof(vis));
    pii res = go(0, 0);
    return  min(res.first, res.second);
}


int main() {
    
    return 0;
}