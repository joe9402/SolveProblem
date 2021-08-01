// K개의 계란으로 N 범위를 확인 할 수 있는 최소 도전 횟수를 dp(K, N) 이라고 할때
// dp(K,N) = min(max(dp(K-1, X-1),dp(K, N-X)) 이다.
// 말로 풀면 어떤 위치 X에서 계란을 떨어뜨릴때
// 깨지는 경우 남은 계란은 1개 줄고 범위는 X보다 낮은 곳 : dp(K-1,X-1)
// 깨지지 않는 경우 계란이 줄지 않고 범위는 N과 X 사이 범위 : dp(K, N-X)
// 단, 두 가지중 최악 상황을 고려해야 하기 때문에 두 값중 max 값을 선택
// 이런 상황들 중 가장 작은 수치가 나오는 X 위치의 값을 선택한다.
// 따라서 dp를 통해 K가 1일때부터 찾아 올라가면 해결 할 수 있다.

class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp1[10001];
        int dp2[10001];
        int* a = dp1;
        int* b = dp2;
    
        //K가 1일경우 N높이에 대해서 N만큼 확인이 필요하다.
        for (int i = 0; i <= n; i++) {
            a[i] = i;
        }

        //K값을 높여가며 dp 계산 시작
        for (int i = 2; i <= k; i++) {
            int x = 1;
            for (int j = 1; j <= n; j++) {
	    // x+1을 했을때 dp값이 더 작아질 경우 x+1 을 한다.
	    // 이때 dp(i,j-1)에서 dp(i,j) 로 진행 할 때 x는 항상 커질수 밖에 없는데 그 이유는
	    // x값이 기존 보다 더 작을 경우 max 값을 판단할때 dp(i, N-x) 에서 N-x 범위가 커지면서
	    // 더 큰값이 발생하기 때문이다.
                while (x < j && max(a[x - 1], b[j - x]) > max(a[(x + 1) - 1], b[j - (x + 1)])) x++;
                b[j] = 1 + max(a[x - 1], b[j - x]);
            }
            int* tmp = a;
            a = b;
            b = tmp;
        }

        return a[n];
    }
};