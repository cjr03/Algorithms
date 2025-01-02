class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numsSize = nums.size();
        k = k % numsSize;
        vector<int> newNums (numsSize);
        for(int i = 0; i < numsSize; ++i){
            newNums[(i+k) % numsSize] = nums[i];
        }
        nums = newNums;
    }
};
