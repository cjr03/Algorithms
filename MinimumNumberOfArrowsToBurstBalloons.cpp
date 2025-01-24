class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; 
        int current = points[0][1]; 

        for (const auto& point : points) {
            if (point[0] > current) {
                ++count;
                current = point[1]; 
            }
        }

        return count;
    }
};
