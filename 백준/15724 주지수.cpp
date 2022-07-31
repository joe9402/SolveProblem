#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int map[1026][1026] = { 0 };
int order[100001][4];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			long k;
			cin >> k;
			map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + k;
		}
	}
	int T;
	cin >> T;

	int x1, y1, x2, y2;
	int res;
	for (int i = 0; i < T; i++) {
		cin >> order[i][0] >> order[i][1] >> order[i][2] >> order[i][3];
	}

	for (int i = 0; i < T; i++) {
		x1 = order[i][0], y1 = order[i][1], x2 = order[i][2], y2 = order[i][3];
		printf("%d\n", map[x2][y2] - (map[x1 - 1][y2] + map[x2][y1 - 1] - map[x1 - 1][y1 - 1]));
	}
}
