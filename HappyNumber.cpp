class Solution {
public:
    int getSquaredSum(int n){
        string num = to_string(n);
        int sum = 0;
        for(char c : num){
            sum += (c - '0') * (c - '0');
        }
        return sum;
    }

    bool isHappy(int n) {
        vector<int> sums;
        int sum = n;
        while(sum >= 1){
            sum = getSquaredSum(sum);
            for(int s : sums){
                if(s == sum){
                    return false;
                }
            }
            sums.push_back(sum);
            if(sum <= 1){
                return true;
            }
        }
        return false;
    }
};
