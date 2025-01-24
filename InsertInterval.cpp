class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output; 
        for (const auto& interval : intervals) {
            if (output.empty() || output.back()[1] < interval[0]) {
                output.push_back(interval);
            } else {
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }
};
