#include <utility>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> mostOccured (nums[0], 0);
        for(int i = 0; i < nums.size(); ++i){
            if (mostOccured.first != nums[i]){
                if (mostOccured.second <= 0){
                    mostOccured.first = nums[i];
                } else {
                    --mostOccured.second;
                }
            } else {
                ++mostOccured.second;
            }
        }
        return mostOccured.first;
    }
};
