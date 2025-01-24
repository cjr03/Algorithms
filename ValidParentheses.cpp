class Solution {
public:
    bool isValid(string s) {
        stack<char> validate;
        unordered_map<char, char> charMatch {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char const & c : s){
            if(charMatch.count(c)){
                if(!validate.empty() && validate.top() == charMatch[c]){
                    validate.pop();
                } else {
                    return false;
                }
            } else {
                validate.push(c);
            }
        }
        return validate.empty();
    }
};
