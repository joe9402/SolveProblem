#include <iostream>
#include <vector>
using namespace std;

/*
* 
* 시간복잡도 O(n)
* 1. 가장 높은 블록를 기준으로 왼,오른쪽으로 갈수록 채워지는 물 높이는 낮아진다
* 2. 왼쪽에서 가장 높은블록까지 물 높이는 점점 높아지며
*    그 높이는 이전에 지나친 블록 중 가장 높은 블록의 높이이다.
* 3. 오른쪽은 2번과 반대방향으로 진행
* Runtime: 8 ms, faster than 83.86% of C++ online submissions for Trapping Rain Water.
* Memory Usage: 14.3 MB, less than 95.77% of C++ online submissions for Trapping Rain Water.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2)return 0;
        int maxpiv = 0;
        int maxh = height[0];
        int sum = 0;
        int res = 0;
        maxh = height[0];
        //왼쪽 -> 오른쪽
        for (int i = 1; i < height.size(); i++) {
            //언제 가장 높은 블록이 나올지 모르기 때문에
            //가장 높은 블록의 높이가 갱신 될때만 최종값인 res에 sum 값을 넘긴다.
            if (height[i] >= maxh) { maxh = height[i]; res = sum; maxpiv = i; }
            else sum += (maxh - height[i]);
        }
        maxh = height[height.size() - 1];
        //오른쪽 -> 왼쪽
        for (int i = height.size() - 2; i > maxpiv; i--) {
            if (height[i] > maxh)maxh = height[i];
            else res += (maxh - height[i]);
        }
        return res;

    }
};

int main() {
    vector<int> h = { 4,2,0,3,2,5 };
    printf("%d\n", Solution().trap(h));
    return 0;
}