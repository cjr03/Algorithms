class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 2, numsSize = nums.size();
        if(numsSize <= 2) return numsSize;
        for(int i = 2; i < numsSize; ++i){
            if(nums[unique-2] != nums[i]) nums[unique++] = nums[i];
        }
        nums.resize(unique);
        return unique;
    }
};
