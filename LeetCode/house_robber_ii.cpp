#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int helper(int house, vector<int>&nums, unordered_map<int, int>& memo, int limit) {
        if(house >= limit) return 0;
        if(memo.find(house) != memo.end()) return memo[house];
        int ret = max(nums[house] + helper(house + 2, nums, memo, limit), helper(house + 1, nums, memo, limit));
        return memo[house] = ret;
    }
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int, int> memo;
        int ans = nums[0] + helper(2, nums, memo, nums.size() - 1);
        memo.clear();
        ans = max(ans, helper(1, nums, memo, nums.size()));
        return ans;
    }
};
