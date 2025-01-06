class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strSize = s.size();
        if(strSize == 1) return 1;
        vector<char> seen;
        int longest = 0;
        for(int i = 0; i < strSize; ++i){
            int removeChars = 0;
            for(int j = 0; j < seen.size(); ++j) if(seen[j] == s[i]) removeChars = j+1;
            seen.erase(seen.begin(), seen.begin() + removeChars);
            seen.push_back(s[i]);
            if(seen.size() > longest) longest = seen.size();
        }
        return longest;
    }
};
