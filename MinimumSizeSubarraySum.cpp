class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = 100001;
        for(int right = 0, left = 0, sum = 0, size = nums.size(); right < size; ++right){
            sum += nums[right];
            while(sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        return minLength < 100001 ? minLength : 0;
    }
};
