#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char org_map[5000][5000];
char new_map[5000][5000];
int NB[4][2];

long double LOSS = 0;
int seed = 3;
extern void test(char map[5000][5000]);

void init() {
	for (int i = 0; i < 5000; i++)
		for (int j = 0; j < 5000; j++)
			org_map[i][j] = new_map[i][j] = 0;
}
void build() {
	int c = 0;
	int x, y;
	while (c < 4) {
		x = rand() % 5000;
		y = rand() % 5000;
		if (org_map[y][x] != 0)
			continue;
		NB[c][0] = x;
		NB[c][1] = y;
		c++;
		org_map[y][x] = new_map[y][x] = -c;
	}
	c = 0;
	int r = 0;
	while (c < 250000) {
		x = rand() % 5000;
		y = rand() % 5000;
		r = (rand() % 4) + 1;
		if (org_map[y][x] != 0)
			continue;
		org_map[y][x] = new_map[y][x] = r;
		c++;
	}
}

void verify() {

	for (int y = 0; y < 5000; y++) {
		for (int x = 0; x < 5000; x++) {
			if ((org_map[y][x] == 0 && new_map[y][x] != 0) ||
				(org_map[y][x] != 0 && new_map[y][x] == 0)) {
				LOSS += (long double)50000000;
			}
		}
	}
	int cnt[4] = { 0 };
	int dx, dy, c;
	for (int y = 0; y < 5000; y++) {
		for (int x = 0; x < 5000; x++) {
			if (new_map[y][x] > 0){
				c = new_map[y][x] - 1;
				cnt[c]++;
				dx = x - NB[c][0];
				dy = y - NB[c][1];
				LOSS += ((dx * dx) + (dy * dy));
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (cnt[i] > 67500) {
			LOSS += (cnt[i] - 67500) * (long double)50000000;
		}
		sum += cnt[i];
	}
	if (sum != 250000) {
		LOSS += (long double)50000000;
	}
}
int main() {
	srand(seed);
	for (int i = 0; i < 10; i++) {
		init();

		build();
		
		test(new_map);
		
		verify();
	}
	printf("LOSS : %.1lf\n", LOSS);
}