#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int j = i;
            while(nums[j] > 0 && nums[j] <= nums.size() && nums[j] - 1 != j && nums[j] != nums[nums[j]-1]) {
                swap(nums[j], nums[nums[j] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] - 1 != i) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};