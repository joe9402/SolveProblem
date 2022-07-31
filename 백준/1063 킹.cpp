#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	string King, Ston;
	int N;
	cin >> King >> Ston;
	cin >> N;
	int king[2], ston[2];
	king[0] = King[0] - 'A';
	king[1] = King[1] - '1';
	ston[0] = Ston[0] - 'A';
	ston[1] = Ston[1] - '1';
	string dir[8] = { "R","L","B","T","RT","LT","RB","LB" };
	int dd[8][2] = { {1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		int x, y;
		for (int j = 0; j < 8; j++) {
			if (order.compare(dir[j]) == 0) {
				int k1, k2, s1, s2;
				s1 = ston[0];
				s2 = ston[1];
				k1 = king[0] + dd[j][0];
				k2 = king[1] + dd[j][1];
				if (k1 == ston[0] && k2 == ston[1]) {
					s1 = ston[0] + dd[j][0];
					s2 = ston[1] + dd[j][1];
				}
				if (k1 < 0 || k1 > 7 || k2 < 0 || k2 > 7 || s1 < 0 || s1 > 7 || s2 < 0 || s2 > 7) {
					continue;
				}
				else {
					king[0] = k1; king[1] = k2;
					ston[0] = s1; ston[1] = s2;
				}
				break;
			}
		}
	}
	King[0] = king[0] + 'A'; King[1] = king[1] + '1';
	Ston[0] = ston[0] + 'A'; Ston[1] = ston[1] + '1';
	cout << King << endl;
	cout<< Ston << endl;
}
