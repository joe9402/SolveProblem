class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i< nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        return dp(nums,sum/2);
    }
    
    bool dp(vector<int>& nums, int dest) {
        bool tab[nums.size()+1][dest+1];
        for(int i = 0; i< dest+1;i++) tab[0][i] = false;
        for(int i = 0; i< nums.size()+1;i++) tab[i][0] = true;
        for(int i = 1 ; i < nums.size();i++){
            for(int j = 1; j < dest+1;j++){
                if (nums[i] <= j) {
                    tab[i][j] = tab[i-1][j-nums[i]] || tab[i-1][j];
                } else {
                    tab[i][j] = tab[i-1][j];
                }
            }
        }
        return tab[nums.size()-1][dest];
    }
};