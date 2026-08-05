class Solution {
public:
    vector<int> ans;

    void check(int k,
               unordered_map<int, int> &indegree,
               vector<vector<int>> &v,
               vector<int> &visited) {

        visited[k] = 1;
        ans.push_back(k);

        for (int i = 0; i < v[k].size(); i++) {
            int nxt = v[k][i];

            indegree[nxt]--;

            if (visited[nxt] == -1) {
                check(nxt, indegree, v, visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> v(n);
        unordered_map<int, int> indegree;

        for (auto it : invocations) {
            v[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<int> visited(n, -1);

        check(k, indegree, v, visited);

        // If a suspicious method still has incoming edges,
        // it means a non-suspicious method invokes it.
        for (int node : ans) {
            if (indegree[node] > 0) {
                vector<int> res;
                for (int i = 0; i < n; i++) {
                    res.push_back(i);
                }
                return res;
            }
        }

        // Return remaining methods
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                res.push_back(i);
            }
        }

        return res;
    }
};