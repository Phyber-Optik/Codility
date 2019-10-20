#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void helper(int k, int cur, int target, int sum, vector<int>& cur_set, vector<vector<int>>& result) {
        if(k < 0 || cur > 10) return;
        if(k == 0 && sum == target) {
            result.push_back(cur_set);
            return;
        }
        cur_set.push_back(cur);
        helper(k - 1, cur + 1, target, sum + cur, cur_set, result);
        cur_set.pop_back();
        helper(k, cur + 1, target, sum, cur_set, result);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>temp;
        helper(k, 1, n, 0, temp, result);
        return result;
    }
};