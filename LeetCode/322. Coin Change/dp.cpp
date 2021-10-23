class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001] = {0};
        dp[0] = -1;
        if(amount == 0) return 0;
        for(int i =0; i<=amount; i++){
            for(int j =0;j<coins.size();j++){
                if(coins[j]>i)continue;
                else {
                    if(i-coins[j] == 0){
                        dp[i] = 1;
                    }
                    else if((dp[i] == 0 || dp[i] > dp[i-coins[j]]+1) && dp[i-coins[j]] !=0){
                        dp[i] = dp[i-coins[j]]+1;
                    }
                }
            }
        }
        if(dp[amount] == 0)return -1;
        return dp[amount];
    }
};