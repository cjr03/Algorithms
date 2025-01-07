class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
        unordered_map<char, int> tFreq;
        for (char c : t) ++tFreq[c];
        unordered_map<char, int> windowFreq;
        int start = 0, minLen = 100001, matched = 0, minStart = 0;
        for (int end = 0; end < s.size(); ++end) {
            char endChar = s[end];
            windowFreq[endChar]++;
            if (tFreq.find(endChar) != tFreq.end() && windowFreq[endChar] <= tFreq[endChar]) {
                matched++;
            }
            while (matched == t.size()) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                char startChar = s[start];
                windowFreq[startChar]--;
                if (tFreq.find(startChar) != tFreq.end() && windowFreq  [startChar] < tFreq[startChar]) {
                    matched--;
                }
                start++;
            }
        }
    return minLen == 100001 ? "" : s.substr(minStart, minLen);
    }
};
