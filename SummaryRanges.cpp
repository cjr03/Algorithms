class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        } else if(nums.size() == 1) {
            return {to_string(nums[0])};
        } else {
            vector<int> range;
            vector<string> output;
            range.push_back(nums[0]);
            for(int i = 1; i < nums.size(); ++i){
                if(range.back() + 1 == nums[i]){
                    range.push_back(nums[i]);
                } else {
                    if(range.size() != 1){
                        output.push_back(to_string(range[0]) + "->" + to_string(range.back()));
                    } else {
                        output.push_back(to_string(range[0]));
                    }   
                    range.clear();
                    range.push_back(nums[i]);
                }
            }
            if(!range.empty()){
                if(range.size() != 1){
                    output.push_back(to_string(range[0]) + "->" + to_string(range.back()));
                } else {
                    output.push_back(to_string(range[0]));
                }   
            }   
        return output;
        }
    }
};
