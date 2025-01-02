class Solution {
public:
    string reverseWords(string s) {
        string word = "", reverseWord = "";
        for(char c : s){
            if(c == ' '){
                if (word != "") {
                    if(reverseWord == "") reverseWord = word;
                    else reverseWord = word + " " + reverseWord;
                }
                word = "";
            } else {
                word += c;
            }
        }
        if(word != "") {
            if(reverseWord == "") reverseWord = word;
            else reverseWord = word + " " + reverseWord;
        }
        return reverseWord;
    }
};
