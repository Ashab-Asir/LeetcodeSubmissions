class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<set<int>> v(n);
        vector<int> in(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            in[b]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int top_node = q.front();
            q.pop();
            for (int neig : adj[top_node]) {
                in[neig]--;
                for (int anc : v[top_node]) {
                    v[neig].insert(anc);
                }
                v[neig].insert(top_node);
                if (in[neig] == 0) {
                    q.push(neig);
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int x : v[i]) {
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};