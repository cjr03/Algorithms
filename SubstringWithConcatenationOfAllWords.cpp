class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;
        const int wordLen = words[0].size();
        const int numWords = words.size();
        if (s.size() < wordLen * numWords) return result;
        unordered_map<string, int> wordCount;
        for (const string word : words) {
            wordCount[word]++;
        }
        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> seenWords;
            int left = i, right = i, count = 0;
            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;
                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    count++;
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
