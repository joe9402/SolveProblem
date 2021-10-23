#include <iostream>
#include <vector>
using namespace std;

/*
* 
* �ð����⵵ O(n)
* 1. ���� ���� ��ϸ� �������� ��,���������� ������ ä������ �� ���̴� ��������
* 2. ���ʿ��� ���� ������ϱ��� �� ���̴� ���� ��������
*    �� ���̴� ������ ����ģ ��� �� ���� ���� ����� �����̴�.
* 3. �������� 2���� �ݴ�������� ����
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
        //���� -> ������
        for (int i = 1; i < height.size(); i++) {
            //���� ���� ���� ����� ������ �𸣱� ������
            //���� ���� ����� ���̰� ���� �ɶ��� �������� res�� sum ���� �ѱ��.
            if (height[i] >= maxh) { maxh = height[i]; res = sum; maxpiv = i; }
            else sum += (maxh - height[i]);
        }
        maxh = height[height.size() - 1];
        //������ -> ����
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