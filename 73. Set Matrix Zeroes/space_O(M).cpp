class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n=matrix[0].size();
        int mtab[200] ={0};
        for(int i =0;i<matrix.size();i++){
            for(int j =0; j<matrix[i].size();j++){
                if(i==0){
                    if(matrix[i][j] == 0){
                         mtab[0] = 1; break;
                    }
                } else {
                    if(matrix[i][j] == 0) mtab[i] = 1;
                    if(matrix[i-1][j] == 0) matrix[i][j] = 0;
                }
                
            }
        }
        for(int i =0;i<matrix.size();i++){
            for(int j =0; j<matrix[i].size();j++){
                if(matrix[m-1][j] == 0 || mtab[i] == 1) matrix[i][j] = 0;
            }
        }
    }
};