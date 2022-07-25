#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;
int N;
int cc;
string result;
void dfs(string res) {
	bool flag = true;
	for (int i = 0; i < N; i++) {
		int a = 1;
		a = a << i;
		if ((cc & a) == 0) {
			flag = false;
			cc += a;
			dfs(res + to_string(i+1) + " ");
			cc -= a;
		}
	}
	if (flag) {
		result += res + "\n";
	}
}
int main() {
	result = "";
	cin >> N;
	cc = 0;
	dfs("");
	cout << result;
	return 0;
}