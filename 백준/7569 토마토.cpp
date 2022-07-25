#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct 
{
	int m;
	int n;
	int h;
	int time;
}Tomato;

int box[101][101][101];
queue<Tomato> q;

int main() {
	int notGoodTomato = 0;
	int goodTomato = 0;
	int N, M, H;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int z;
				cin >> z;
				box[k][j][i] = z;
				if (z == 1) {
					//큐에 넣기
					Tomato tomato = { k, j, i, 0 };
					q.push(tomato);
				}
				if (z == 0) {
					notGoodTomato++;
				}
			}
		}
	}
	if (notGoodTomato <= 0) {
		cout << "0";
        return 0;
	}
	int dh[6] = { 1,-1,0,0,0,0 };
	int dn[6] = { 0,0,1,-1,0,0 };
	int dm[6] = { 0,0,0,0,1,-1 };
	int res = 0;
	while (!q.empty()) {
		Tomato tomato = q.front();
		res = tomato.time;
		for (int i = 0; i < 6; i++) {
			int mm = tomato.m + dm[i];
			int nn = tomato.n + dn[i];
			int hh = tomato.h + dh[i];
			if (hh >= 0 && hh < H && nn >= 0 && nn < N && mm >= 0 && mm < M) {
				if (box[mm][nn][hh] == 0) {
                    box[mm][nn][hh] = 1;
					Tomato newTomato = { mm,nn,hh,tomato.time + 1 };
					q.push(newTomato);
					notGoodTomato--;
				}
			}
		}
		q.pop();
	}
	if (notGoodTomato > 0)
		cout << "-1";
	else
		cout << res;

}