//2번만 살 수 있으므로 어떤 시점의 앞,뒤 에서 가장 큰 이득의 합중 가장 큰 값이다.
//dp 를 활용하여 어떤 시점보다 뒤에서 가장 큰 이득을 보는 경우를 저장한다.
//다시 순회하며 어떤 시점보다 앞에서 가장 큰 이득을 보는 경우를 구하고 
//해당 값과 같은 시점의 dp 저장값을 더하여 최댓값을 갱신한다.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int dp[N] ;
        int result = 0;
        int max = prices[N-1];
        dp[N-1] = 0;
        for(int i = N-2;i>=0;i--){
            if(max-prices[i] > dp[i+1]){ dp[i] = max-prices[i]; continue;}
            if(prices[i]>max) max = prices[i];
            dp[i] = dp[i+1];
        }
        int min = prices[0];
        int a = 0;
        for(int i =1;i<N;i++){
            if(prices[i]-min > a){a = prices[i]-min;}
            if(prices[i]<min)min = prices[i];
            if(result < a+ dp[i])result = a + dp[i];
        }
        
        return result;
    }
};