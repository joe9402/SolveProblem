class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int x, int y, int num){
        grid[x][y] = num;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        int n = grid.size();
        
        for(int i =0; i<4;i++){
            int xx = x + dx[i]; int yy = y + dy[i];
            if(xx >= n || yy >= n || xx <0 || yy <0) continue;
            if(grid[xx][yy] == 1){
                dfs(grid,xx,yy,num);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int landnum = 2;
        for(int i =0; i < n; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j, landnum++);
                    if(landnum > 3) break;
                }
            }
            if(landnum > 3) break;
        }
        int stack[10001][2];
        int top3 =0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 3) {
                    stack[top3][0] = i;
                    stack[top3][1] = j;
                    top3++;
                }
            }
        }
        int res = 10000;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 2) {
                    for(int k = 0; k < top3; k++){
                        int count = abs(stack[k][0]-i) + abs(stack[k][1]-j) -1;
                        if(res > count) res = count;
                    }
                }
            }
        }
        return res;
    }
    
    
};