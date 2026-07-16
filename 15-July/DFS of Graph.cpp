class Solution {
private:
    void dfs(int src, vector<bool> &vis, vector<int> &res, vector<vector<int>> &adj){
        vis[src] = true;
        res.push_back(src);
        for(int &neighbourNode : adj[src]){
            if(! vis[neighbourNode]){
                dfs(neighbourNode, vis, res, adj);
            }
        }
    }
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> res;
        int n = adj.size();
        vector<bool> vis(n, false);
        dfs(0, vis, res, adj);
        return res;
    }
};