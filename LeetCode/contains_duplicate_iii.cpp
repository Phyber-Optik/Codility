#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int>mp;
        int l = 0, r = 0;
        long long min_diff = INT_MAX * 10LL;
        while(r < nums.size()) {
            mp[nums[r]]++;
            if(r - l > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(mp.find(nums[l]));
                l++;
            }
            auto it = mp.find(nums[r]);
            if(it->second > 1) {
                min_diff = 0;
                break;
            }
            if(it != mp.begin()) {
                long long cur_diff = abs((long long)prev(it)->first - (long long)nums[r]);
                if(cur_diff < min_diff)
                    min_diff = cur_diff;
            }
            if(it != prev(mp.end())) {
                long long cur_diff = abs((long long)next(it)->first - (long long)nums[r]);
                if(cur_diff < min_diff)
                    min_diff = cur_diff;
            }
            r++;
        }
        return min_diff <= t;
    }
};
