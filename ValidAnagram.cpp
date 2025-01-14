class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); ++i){
            bool found = false;
            for(int j = 0; j < t.size(); ++j){
                if(s[i] == t[j]){
                    t.erase(t.find(s[i]), 1);
                    found = true;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
};
