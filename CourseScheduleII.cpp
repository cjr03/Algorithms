class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(auto & pre : prerequisites) g[pre[1]].push_back(pre[0]);
        vector<int> s(numCourses, 0), p;
        for(int i = 0; i < numCourses; ++i){
            if(s[i] == 0 && getCycle(i, g, s, p)) return {};
        }
        reverse(p.begin(), p.end());
        return p;
    }

private:
    bool getCycle (int pre, vector<vector<int>> & g, vector<int> & s, vector<int> & p) {
        s[pre] = 1;
        for(int post: g[pre]){
            if(s[post] == 1) return true;
            if(s[post] == 0 && getCycle(post, g, s, p)) return true;
        }
        s[pre] = 2;
        p.push_back(pre);
        return false;
    }
};
