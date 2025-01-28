class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> stk; 
        int result = 0, current_num = 0, sign = 1; 
        for (char c : s) {
            if (c == ' ') {
                continue;
            } else if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
            } else {
                result += sign * current_num;
                current_num = 0;
                if (c == '+') {
                    sign = 1; 
                } else if (c == '-') {
                    sign = -1; 
                } else if (c == '(') {
                    stk.push({result, sign}); 
                    result = 0;
                    sign = 1; 
                } else if (c == ')') {
                    auto [prev_res, prev_sign] = stk.top(); 
                    stk.pop();
                    result = prev_res + prev_sign * result;
                }
            }
        }
        result += sign * current_num;
        return result;
    }
};
