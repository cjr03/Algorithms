class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> candy(size, 1);
        for(int i = 1; i < size; ++i){
            if(ratings[i-1] < ratings[i]) candy[i] = candy[i-1] + 1;
        }
        int totalCandies = candy[size-1];
        for(int i = size - 2; i >= 0; --i){
            if(ratings[i+1] < ratings[i]) candy[i] = max(candy[i], candy[i+1] + 1);
            totalCandies += candy[i];
        }
        return totalCandies;
    }
};
