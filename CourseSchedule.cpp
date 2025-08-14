class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (vector<int>& pre : prerequisites) {
            g[pre[1]].push_back(pre[0]);
        }
        vector<int> s(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (s[i] == 0 && hasCycle(i, g, s)) {
                return false;
            }
        }
        return true;
    }

private:
    bool hasCycle (int & pre, vector<vector<int>> & g, vector<int> & s) {
        s[pre] = 1;
        for(int post : g[pre]){
            if (s[post] == 1) return true;
            if (s[post] == 0 && hasCycle(post, g, s)) return true;
        }
        s[pre] = 2;
        return false;
    }
};
