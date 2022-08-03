#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int res[501][501] = { 0 };
int map[501][501];
int N;

bool in_size(int a, int b, int n) {
	if (a >= 0 && a < n && b >= 0 && b < n)
		return true;
	else
		return false;
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int x, int y) {
	int mm = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (in_size(xx,yy,N) && map[x][y] < map[xx][yy]) {		
			int j;
			if (res[xx][yy] > 0) {
				j = res[xx][yy] + 1;
			}
			else {
				j = dfs(xx, yy)+1;
			}
			if (mm < j) {
				mm = j;
			}
		}
	}
	res[x][y] = mm;
	return mm;
};

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int output = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (res[i][j] == 0) {
				int k = dfs(i, j);
				if (output < k)
					output = k;
			}			
		}
	}
	cout << output;
}
