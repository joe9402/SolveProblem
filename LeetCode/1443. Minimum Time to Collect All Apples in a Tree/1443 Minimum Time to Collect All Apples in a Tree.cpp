class Solution {
public:
    int count;
    int check[100001] = {0};
    vector<vector<int>> tree;
    bool dfs(int vertex, vector<bool>& hasApple) {
        check[vertex] = 1;
        bool now = hasApple[vertex];
        for(int i = 0 ; i < tree[vertex].size(); i++ ){
            if (check[tree[vertex][i]] == 0 && dfs(tree[vertex][i], hasApple)) {
                count += 2;
                now = true;
            }
        }
        return now;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        tree.resize(n);
        for(int i = 0; i < edges.size();i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        count = 0;
        dfs(0, hasApple);
        return count;
    }
};