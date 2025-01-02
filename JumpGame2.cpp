class Solution {
public:
    int jump(vector<int>& nums) {
        int end = nums.size();
        if(end <= 1) return 0;
        int jumps = 0, farthest = 0, currentEnd = 0;
        for(int i = 0; i < end; ++i){
            farthest = max(farthest, i + nums[i]);
            if(i >= currentEnd){
                ++jumps;
                currentEnd = farthest;
                if(currentEnd >= end - 1) break;
            }
        }
        return jumps;
    }
};
