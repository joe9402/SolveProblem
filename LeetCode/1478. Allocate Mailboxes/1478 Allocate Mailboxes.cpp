class Solution {
public:
    //구간의 우체통까지의 최소값
    int calDistance(int a, int b, vector<int>& houses) {
        //정렬된 구간 중간의 위치가 적절한 우체통의 위치이다.
        //홀수일 경우 자명하게 중간값
        //짝수의 경우 중간위치에서 양쪽 집 중에 어느 것을 선택해도 동일한 수치 만큼 증감이 발생하므로 역시 중간값
        //따라서 (a+b)/2 의 값의 집으로 중간 집 선정
        int mid = houses[(a+b)/2];
        int sum = 0;
        for(int i =a;i<b;i++){
            sum += abs(houses[i]-mid);
        }
        return sum;
    }
    
    // N <= 100, K <= 100 으로 최댓값 고려
    // N*N*K 의 dp 준비
    int dp[101][101][101];
    int MAX = 1000000000;
    int dpSolve(int start, int end, int k, vector<int>& houses) {
        //start == end 일 경우 구간에 집이 없고 k==0로 우체통도 없는 경우 맞는 상황임으로 0을 리턴
        if(k == 0 && start == end) return 0;
        //k==0인데 구간에 집이 있거나, k != 0인데 구간에 집이 없는 경우 잘못된 상황임으로 MAX 리턴
        if(k == 0 || start == end) return MAX;
        //이미 계산이 되어있는 상황일때는 추가 계산 필요 없이 바로 리턴
        if(dp[start][end][k] != -1) return dp[start][end][k];
        int ans = MAX;
        for(int i = start; i < end; i++) {
            //i 위치를 기준으로 왼쪽에 깃발 1개 오른쪽에 K-1 개의 깃발이 있는 경우를 계산
            // 전체 구간을 i에 대하여 확인하여 start, end 사이에 k개의 깃발이 있는 경우 가장 짧은 합 
            ans = min(ans,(calDistance(start,i+1,houses)+dpSolve(i+1,end,k-1,houses)));
        }
        dp[start][end][k] = ans;
        return ans;
    }
    
    int minDistance(vector<int>& houses, int k) {
        //houses 정렬
        sort(houses.begin(),houses.end());
        memset(dp,-1,sizeof(dp));
        return dpSolve(0,houses.size(),k,houses);
    }
    //아래 디스커스 참조
    //https://leetcode.com/problems/allocate-mailboxes/discuss/1982261/C%2B%2B-or-Memorization
};