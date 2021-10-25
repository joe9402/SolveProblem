class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int min = 2000001;
        if(triangle.size() ==1 ) return triangle[0][0];
        for(int i = 1 ; i< triangle.size();i++){
            for(int j = 0 ; j<triangle[i].size();j++){
                if(j==0){
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j== triangle[i].size()-1) {
                    triangle[i][j] += triangle[i-1][triangle[i-1].size()-1];
                } else {
                    if(triangle[i-1][j-1] > triangle[i-1][j]) triangle[i][j] += triangle[i-1][j];
                    else triangle[i][j] += triangle[i-1][j-1];
                }
                if(i == triangle.size()-1 && min > triangle[i][j]){
                    min = triangle[i][j];
                }
            }
        }
        return min;
    }
};