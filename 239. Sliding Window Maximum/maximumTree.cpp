/*
Runtime: 568 ms, faster than 9.74% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 130.8 MB, less than 69.89% of C++ online submissions for Sliding Window Maximum.
O(NlogN)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bt[270000];

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int MAX;
	int N;
	N = nums.size();
	vector<int> res;
	int start = 1;
	while (start < N)
	{
		start *= 2;
	}
	for (int i = 0; i < 2 * start; i++) {
		bt[i] = -1000000;
	}
	for (int i = 0; i < N; i++) {
		bt[start + i] = nums[i];
	}
	for (int i = start +N - 1; i > 1; i--) {
		if (bt[i / 2] < bt[i])bt[i / 2] = bt[i];
	}
	for (int i = start; i <= start+N-k; i++) {
		MAX = 0;
		int l[2] = { i,0 };
		int r[2] = { i + k - 1,0 };
		if (bt[l[0]] > bt[r[0]])MAX = bt[l[0]];
		else MAX = bt[r[0]];
		while (l[0] != r[0]) {
			//ÃþÀÌ ´Ù¸£¸é ÃþºÎÅÍ ¸ÂÃá´Ù
			if (l[1] > r[1]) {
				if (r[0] % 2 == 0) {
					r[0]--;
				}
				r[0] /= 2;
				r[1]++;
			}
			else if (l[1] < r[1]) {
				if (l[0] % 2 != 0) {
					l[0]++;
				}
				l[0] /= 2;
				l[1]++;
			}
			else {
				if (bt[l[0]] > bt[r[0]]){
					if (r[0] % 2 == 0) r[0]--;
					else {
						r[0] /= 2;
						r[1]++;
					} 
				}
				else { 
					if (l[0] % 2 != 0)l[0]++;
					else {
						l[0] /= 2;
						l[1]++;
					}
				}
			}
			if (MAX < bt[l[0]])MAX = bt[l[0]];
			if (MAX < bt[r[0]])MAX = bt[r[0]];\
		}
		res.push_back(MAX);
	}
	return res;
}

int main(void) {
	/*vector<int> v = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;*/
	vector<int> v = { 7,2,4 };
	int k = 2;

	vector<int> return_value = maxSlidingWindow(v, k);

	for (int i = 0; i < return_value.size(); i++)
		cout << return_value[i] << " ";
	return 0;
}