class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        char cLast = 'N';
        for(char c : s){
            switch(c){
                case 'I':
                    number += 1;
                    break;
                case 'V':
                    if(cLast == 'I') number += 3;
                    else number += 5;
                    break;
                case 'X':
                    if(cLast == 'I') number += 8;
                    else number += 10;
                    break;
                case 'L':
                    if(cLast =='X') number += 30;
                    else number += 50;
                    break;
                case 'C':
                    if(cLast =='X') number += 80;
                    else number += 100;
                    break;
                case 'D':
                    if(cLast =='C') number += 300;
                    else number += 500;
                    break;
                case 'M':
                    if(cLast =='C') number += 800;
                    else number += 1000;
                    break;
            }
            cLast = c;
        }
        return number;
    }
};
