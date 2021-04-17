//1. 완전탐색 : 시간초과 :
//  완전탐색을 할 경우 시간복잡도가 O(2^(2N)) 으로
//  N 20만초과해도 10^12 으로 매우 커진다.
//2. greedy : 틀림 :
//  greedy 하게 내려가며 최댓값 , 돌아오며 최댓값을 선택할 경우
//  정해라는 것이 보장되지 않는다.
//3. dp : 풀림
//idea : 한명이 갔다 오는 것과 한번에 두 명이 가는 것이 같다.
//a,b 를 각 사람이라 할때
//dp(a,b)는 a,b가 해당 위치에서 N-1,N-1 까지 체리를 가지러 가는 최대값이다.
//주의사항 :
//1. 위치가 겹치는 경우 : 한명만 값을 추가한다.
//2. N-1,N-1 에 도착하지 못하는 경우 : 
//  경계상황에서 dp return을 매우 큰 음수로 주면
//  dp가 재귀적으로 max를 확인할때 설정한 매우 큰 음수를 포함하게 되어
//  최종적으로 음수를 return 한다.
//공간복잡도 O(N^4)
//시간복잡도 O(N^4)


class Solution {
public:
    int map[51][51][51][51];
    int N;
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        for(int i =0;i<N;i++){ for(int j =0;j<N;j++){
            for(int k =0;k<N;k++){for(int l =0;l<N;l++){
             map[i][j][k][l] = -1;   
            }}
        }}
        return max(0,dp(grid,0,0,0,0));
    }
    
    int dp(vector<vector<int>>& grid,int x1,int y1,int x2,int y2){
        int res = 0;
        if(x1 >= N || y1 >=N || x2>=N || y2 >= N || grid[x1][y1] == -1 || grid[x2][y2] == -1)return -99999999;
        if(map[x1][y1][x2][y2] != -1) return map[x1][y1][x2][y2];
        if(x1 == N-1 && y1 == N-1) return grid[x1][y1]; 
        
        if(x1 == x2)res += grid[x1][y1];
        else res += grid[x1][y1] + grid[x2][y2];
        res += max(max(dp(grid,x1+1,y1,x2+1,y2), dp(grid,x1,y1+1,x2+1,y2)),
                   max(dp(grid,x1+1,y1,x2,y2+1), dp(grid,x1,y1+1,x2,y2+1)));
        map[x1][y1][x2][y2] = res;
        
        return res;
    }
    
};
