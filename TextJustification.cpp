class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line, lines;
        int lineLength = 0;
        for(string word : words){
            if(lineLength + line.size() + word.size() > maxWidth){
                string currentLine = "";
                int spaces = maxWidth - lineLength, slots = line.size() - 1;
                if(slots == 0){
                    currentLine = line[0] + string(spaces, ' ');
                } else {
                    int spaceSize = spaces / slots;
                    int extraSpaces = spaces % slots;
                    for(int i = 0; i < slots; ++i){
                        currentLine += line[i];
                        currentLine += string(spaceSize + (i < extraSpaces ? 1 : 0), ' ');
                    }
                    currentLine += line.back();
                }
                lines.push_back(currentLine);
                line.clear();
                lineLength = 0;
            }
            lineLength += word.length();
            line.push_back(word);
        }
        string endLine = "";
        for(int i = 0; i < line.size(); ++i){
            if (i > 0) endLine += ' ';
            endLine += line[i];
        }
        endLine += string(maxWidth - endLine.size(), ' ');
        lines.push_back(endLine);
        return lines;
    }
};
