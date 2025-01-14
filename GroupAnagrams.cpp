class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> freq;

        for (char c : s) {
            ++freq[c];
        }

        for (char c : t) {
            if (--freq[c] < 0) {
                return false; 
            }
        }

        return true;
    }
     
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (string s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            anagramGroups[sortedS].push_back(s);
        }

        vector<vector<string>> allAnagrams;
        for (auto& group : anagramGroups) {
            allAnagrams.push_back(group.second);
        }

        return allAnagrams;
    }
};
