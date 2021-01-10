#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2)return 0;
        int maxpiv = 0;
        int maxh = height[0];
        int sum = 0;
        int res = 0;
        maxh = height[0];
        for (int i = 1; i < height.size(); i++) {
            if (height[i] >= maxh) { maxh = height[i]; res = sum; maxpiv = i; }
            else sum += (maxh - height[i]);
        }
        maxh = height[height.size() - 1];
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