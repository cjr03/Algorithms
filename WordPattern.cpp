class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_set<string> usedWords;
        vector<string> strings;
        string current = "";
        for(char c : s){
            if(c != ' '){
                current += c;
            } else {
                strings.push_back(current);
                current = "";
            }
        }
        if(!current.empty()){
            strings.push_back(current);
        }
        if(pattern.length() != strings.size()){
            return false;
        }
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string word = strings[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != word) {
                    return false; 
                }
            } else {
                if (usedWords.count(word)) {
                    return false;
                }
                charToWord[c] = word;
                usedWords.insert(word);
            }
        }

        return true;
    }
};
