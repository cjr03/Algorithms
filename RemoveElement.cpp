class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numsSize = nums.size(), removed = 0;
        for(int i = 0; i < numsSize - removed; ){
            if (nums[i] == val) {
                int j = i;
                while( j < numsSize - removed - 1 ){
                    nums[j] = nums[j+1];
                    j++;
                }
                nums.pop_back();
                ++removed;
            } else {
                ++i;
            }
        }
        return numsSize - removed;
    }
};
