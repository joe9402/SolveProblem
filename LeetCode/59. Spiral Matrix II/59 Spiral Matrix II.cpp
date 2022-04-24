class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int x =0,y=0,count=1;
        int dy[4]={1,0,-1,0};
        int dx[4] = {0,1,0,-1};
        int dir = 0;
        res[0][0] = 1;
        while(count < n*n){
            count++;
            int xx = x+dx[dir],yy=y+dy[dir];
            if (yy<0 || yy >=n || xx <0 || xx >=n || res[xx][yy] != 0) {
                dir++;
                dir = dir%4;
                xx =x + dx[dir]; yy=y+dy[dir];
            }
            res[xx][yy] = count;
            x=xx;y=yy;
           
        }
        return res;
    }
};