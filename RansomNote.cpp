class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(char letter : ransomNote){
            int found = false;
            for(char option : magazine){
                if(letter == option){
                    magazine.erase(magazine.find(option), 1);
                    found = true;
                    break;
                }
            }
            if(!found) {
                return false;
            }
        }
        return true;
    }
};
