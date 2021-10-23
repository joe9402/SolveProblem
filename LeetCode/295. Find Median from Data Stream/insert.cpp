#include <iostream>
#include <vector>
#include <stdio.h>

int map[100][100];
int N, M, K;
int count;

void DFS(int x, int y) {
	map[x][y] = count;
	if (x > 0 && map[x - 1][y] == 0)DFS(x - 1, y);
	if (x < N - 1 && map[x + 1][y] == 0)DFS(x + 1, y);
	if (y > 0 && map[x][y - 1] == 0)DFS(x, y - 1);
	if (y < M - 1 && map[x][y + 1] == 0)DFS(x, y + 1);
}

int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = 0;
		}
	}
	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				map[j][k] = -1;
			}
		}
	}
	count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				count++;
				DFS(i, j);
			}
		}
	}
	printf("%d", count);
	return 0;
}