//Runtime: 12 ms, faster than 41.48 % of C++ online submissions for Dungeon Game.
//Memory Usage : 8.7 MB, less than 86.42 % of C++ online submissions for Dungeon Game.
//MAX health is N*M*1000 + 1 < 40000001 < 2^26
//따라서 이진 탐색시 최대 26번 탐색
//Time : O(N*M*log(N*M))

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int hp[200][200];
	    int N = dungeon.size();
	    int M = dungeon[0].size();
	    int r = ((N + M) * 1000) + 1;
	    int l = 1;
	    int mid = (r + l) / 2;
	    while (r > l) {
    		
	    	for (int i = 0; i < N; i++) {
		    	for (int j = 0; j < M; j++) {
			    	if (i == 0 && j == 0) {
					    hp[0][0] = mid + dungeon[0][0];
				    }
				    else if (i == 0) {
                        if(hp[i][j-1] <=0)hp[i][j] = 0;
    					else hp[i][j] = hp[i][j - 1] + dungeon[i][j];
    				}
				    else if (j == 0) {
                        if(hp[i-1][j] <=0)hp[i][j] = 0;
    					else hp[i][j] = hp[i - 1][j] + dungeon[i][j];
				    }
				    else {
    					if (hp[i - 1][j] > hp[i][j - 1])
    						hp[i][j] = hp[i - 1][j];
    					else
    						hp[i][j] = hp[i][j - 1];
                        if(hp[i][j] <=0)hp[i][j] = 0;
                        else hp[i][j] +=dungeon[i][j];
	    			}
    			}   
		    }
            printf("%d %d %d\n",l,r,mid);
		    if (hp[N-1][M-1]>0) {
			    r = mid;
		    }
		    else {
			    l = mid + 1;
		    }
            mid = (r + l) / 2;
           
	    }
	    return l;
    }
};