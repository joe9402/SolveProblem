// 1. 캔디의 개수를 높이로 하여 캔디들의 분배를 그래프로 표현하면 결국 여러개의 산모양으로 분포하게 된다.
// 이때 각 산모양의 양 끝은 1이고 그 사이의 꼭대기 방향으로 1씩 커지게 된다.
// 2. 각 산모양 1개당 총 캔디의 개수는 상승 횟수를 u , 하강 횟수를 d 라고 할때 1~u 까지의 자연수합 + 1~d 까지의 자연수합 + 꼭대기의 개수가 된다.
// 이때 꼭대기의 개수는 u,d 중 큰수 +1 이다.
// 3. 따라서 ratings 를 지나가면서 캔디의 개수가 1인 시점까지의 상승횟수, 하강횟수를 기록하면 구간의 캔디 합을 구할 수 있다.
// 4. 캔디의 개수가 1이 되는 시점은 [1 0 1] , [1 0 0] , [0 1 1], [0 0 1] 과 같이 중간 지점이 가장 낮은경우 , 혹은 중간지점부터 양쪽중 어느 곳이 평탄한 경우이다.

class Solution {
public:
    int count(int n){
        return (n*(n+1))/2;
    }
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) return ratings.size();

        int oldSlope = 0;
        int newSlope = 0;
        int up = 0;
        int down = 0;
        int candys = 0;
        for (int i = 1; i < ratings.size(); i++) {
            newSlope = ratings[i] > ratings[i - 1] ? 1 : ratings[i] < ratings[i - 1] ? -1 : 0;

            if (oldSlope > 0 && newSlope == 0 || oldSlope < 0 && newSlope >= 0) {
	    //여기서 꼭대기에 +1 이 없는 이유는 이 구간의 끝점과 다음구간의 시작점 겹침을 해소하기 위해 -1을 해서 이다.
                candys += count(up) + count(down) + max(up, down);
                up = 0;
                down = 0;
            }
            if (newSlope > 0) up++;
            else if (newSlope < 0) down++;
            else candys++; // newSlope == 0 인 경우에는 산의 시작점이 1칸 뒤로 밀리고 해당부분은 캔디 1개이기 때문에 +1 한다.
            oldSlope = newSlope;
        }
        //마지막 구간이 평탄구간이 아닐경우 for문 안에서 계산되지 않기 때문에 잔여 계산을 처리한다.
        candys += count(up) + count(down) + max(up, down) + 1;
        return candys;
    }    
};