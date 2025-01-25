class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s; 
        stringstream ss(path); 
        string part, result = "";
        while (getline(ss, part, '/')) {
            if (part == "." || part.empty()) {
                continue;
            } else if (part == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(part);
            }
        }
        while (!s.empty()) {
            result = "/" + s.top() + result;
            s.pop();
        }
        return result.empty() ? "/" : result;
    }
};
