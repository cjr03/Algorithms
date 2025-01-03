class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int row = 0;
        vector<string> rows (min(numRows, static_cast<int>(s.size())));
        bool down = false;
        for(char c : s){
            rows[row] += c;
            if(row <= 0 || row >= numRows - 1) down = !down;
            down ? ++row : --row;
        }
        string zigZag = "";
        for(string z : rows) zigZag += z;
        return zigZag;
    }
};
