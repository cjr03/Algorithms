class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, char> mappings;
        for(int i = 0; i < s.size(); ++i){
            if(mappings.find(s[i]) == mappings.end()){
                mappings[s[i]] = t[i];
            } else {
                if (mappings[s[i]] != t[i]){
                    return false;
                }
            }
        }
        unordered_map<char, bool> valid;
        for(pair<char, char> pair : mappings){
            if(valid.find(pair.second) == valid.end()){
                valid[pair.second] = true;
            } else {
                return false;
            }
        }
        return true;
    }
};
