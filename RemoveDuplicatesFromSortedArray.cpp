class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsSize = nums.size(), unique = 1;
        for(int i = 1; i < numsSize; ++i) {
            if (nums[i] != nums[i-1]) {
                nums[unique++] = nums[i];
            }
        }
        return unique;
    }
};
