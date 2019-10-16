#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    #define pii pair<int, int>

    struct pii_hasher {
        size_t operator () (const pii &key) const {
            using std::size_t;
            using std::hash;
            using std::string;

            size_t res = 17;
            res = res * 31 + hash<int>()(key.first);
            res = res * 31 + hash<int>()(key.second);
            return res;
        }
    };

    int dx[4] = {-1, 0, 0, +1};
    int dy[4] = {0, -1, +1, 0};
    bool helper(int pos, string &word, int x, int y, vector<vector<char>>& board, int m, int n, unordered_set<pii, pii_hasher> &visited) {
        if(pos == word.size()) return true;
        visited.insert(pii(x, y));
        bool ret = false;
        for(int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if(visited.find(pii(tx, ty)) == visited.end() && tx >= 0 && tx < m && ty >= 0 && ty < n && board[tx][ty] == word[pos]) {
                ret |= helper(pos + 1, word, tx, ty, board, m, n);
            }
        }
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return true;
        int m = board.size();
        int n = board[0].size();
        unordered_set<pii, pii_hasher>visited;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited.clear();
                if(word[0] == board[i][j] && helper(1, word, i, j, board, m, n, visited)) return true;
            }
        }
        return false;
    }
};