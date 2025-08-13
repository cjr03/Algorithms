class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < equations.size(); i++) {
            string n1 = equations[i][0], n2 = equations[i][1];
            double val = values[i];
            g[n1].push_back({n2, val});
            g[n2].push_back({n1, 1.0 / val});
        }

        vector<double> solutions;
        for (auto &q : queries) {
            string start = q[0], end = q[1];
            if (!g.count(start) || !g.count(end)) {
                solutions.push_back(-1.0);
            } else if (start == end) {
                solutions.push_back(1.0);
            } else {
                solutions.push_back(bfs(g, start, end));
            }
        }
        return solutions;
    }
private:
    double bfs (unordered_map<string, vector<pair<string, double>>>& g, string start, string end) {
        queue<pair<string, double>> q;
        unordered_map<string, bool> visited;
        q.push({start, 1.0});
        visited[start] = true;

        while (!q.empty()) {
            pair<string, double> cur = q.front();
            q.pop();
            if (cur.first == end) return cur.second;
            
            for(pair<string, double>& next : g[cur.first]) {
                if (!visited[next.first]) {
                    visited[next.first] = true;
                    q.push({next.first, cur.second * next.second});
                }
            }
        }

        return -1.0;
    }
};
