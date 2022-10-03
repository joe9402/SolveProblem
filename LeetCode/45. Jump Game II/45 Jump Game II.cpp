class Solution {
public:
    int jump(vector<int>& nums) {
        /*477 ms	16.6 MB	cpp
        dp 배열을 만들어 숫자를 모두 변경
        int dp[10001] = {0};
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j<= i+nums[i] && j < nums.size();j++){
                if(dp[j] == 0 || dp[j] > dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        return dp[nums.size()-1];*/
        
        //24 ms	16.6 MB	cpp
        //1. n번 점프 했을 때 도착 가능한 영역은 nowBound 이하이다.
        //2. nowBound 영역을 넘어가려면 점프를 해야하며 nowBound 이하 영역에서 가장 멀리 도착 가능한 곳은 nextBound이다.
        //3. n+1번 점프 했을때 도착 할수 있는 범위는 nextBount 였으므로 nowBound = nextBound 해준다.
        int jumpCount = 0, nowBound = 0, nextBound = 0;
        for(int i = 0 ; i < nums.size()-1; i++){
            if(nextBound < i + nums[i]) {
                nextBound = i + nums[i];
            }
            if(i == nowBound) {
                jumpCount++;
                nowBound = nextBound;
            }
        }
        return jumpCount;
    }
};