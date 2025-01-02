#include <algorithm>
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> sortedCitations(citations);
        sort(sortedCitations.begin(), sortedCitations.end());
        int size = sortedCitations.size(), h = 0;
        for(int i = size - 1; i >= 0; --i){
            if(sortedCitations[i] > h){
                ++h;
            } else return h;
        }
        return h;
    }
};
