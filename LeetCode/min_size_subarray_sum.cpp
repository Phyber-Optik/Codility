class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int cur_sum = 0, min_len = nums.size(), l = 0, r = 0;
        bool found = false;
        while(r < nums.size()) {
            cur_sum += nums[r];
            while(l <= r && cur_sum >= s) {
                found = true;
                if(r - l + 1 < min_len) {
                    min_len = r - l + 1;
                }
                cur_sum -= nums[l++];
            }
            r++;
        }
        return found ? min_len: 0;
    }
};