#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void helper(vector<int>&nums, int ind, vector<int> &cur, vector<vector<int>> &subsets) {
        if(ind == nums.size()) {
            subsets.push_back(cur);
            return;
        }
        cur.push_back(nums[ind]);
        helper(nums, ind + 1, cur, subsets);
        cur.pop_back();
        helper(nums, ind + 1, cur, subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        helper(nums, 0, cur, ans);
        return ans;
    }
};
