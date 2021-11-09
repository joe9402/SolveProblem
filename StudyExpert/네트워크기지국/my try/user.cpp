#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_COUNT 67500
using namespace std;

int NetPoint[5][2];
int sumCount[5];
int client[250000][2];
//LOSS : 7241765847512.0

struct compare {
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		return a.first > b.first;
	}
};

int dist(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2) * abs(y1 - y2));
}

void init_user() {
	for (int i = 0; i < 250000; i++) {
		client[i][0] = 0; client[i][1] = 0;
	}
	for (int i = 0; i < 5; i++) {
		sumCount[i] = 0;
		NetPoint[i][0] = 0; NetPoint[i][1] = 0;
	}
}

void test(char map[5000][5000]) {
	init_user();
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> lev2;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> lev3;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> lev4;
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 5000; j++) {
			if (map[i][j] < 0) {
				NetPoint[map[i][j] * (-1)][0] = i;
				NetPoint[map[i][j] * (-1)][1] = j;
			}
		}
	}
	int top1 = 0;
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 5000; j++) {
			if (map[i][j] > 0) {
				client[top1][0] = i; client[top1][1] = j;
				priority_queue<pair<int, pair<int, int>>> temp;
				for (int k = 1; k < 5; k++) {
					pair<int, pair<int, int>> im;
					im.first = dist(i, j, NetPoint[k][0], NetPoint[k][1]);
					im.second = make_pair(top1, k);
					temp.push(im);
				}
				lev4.push(temp.top()); temp.pop();
				lev3.push(temp.top()); temp.pop();
				lev2.push(temp.top()); temp.pop();
				map[i][j] = temp.top().second.second;
				sumCount[map[i][j]]++;
				top1++;
			}
		}
	}
	for (int i = 0; i < 250000; i++) {
		pair<int, pair<int, int>> temp;
		temp = lev2.top();
		int pos = temp.second.first;
		int x = client[pos][0], y = client[pos][1];
		int server = temp.second.second;
		if (sumCount[map[x][y]] > MAX_COUNT) {
			sumCount[map[x][y]]--;
			map[x][y] = server;
			sumCount[map[x][y]]++;
		}
		lev2.pop();
	}
	for (int i = 0; i < 250000; i++) {
		pair<int, pair<int, int>> temp;
		temp = lev3.top();
		int pos = temp.second.first;
		int x = client[pos][0], y = client[pos][1];
		int server = temp.second.second;
		if (sumCount[map[x][y]] > MAX_COUNT) {
			sumCount[map[x][y]]--;
			map[x][y] = server;
			sumCount[map[x][y]]++;
		}
		lev3.pop();
	}
	for (int i = 0; i < 250000; i++) {
		pair<int, pair<int, int>> temp;
		temp = lev4.top();
		int pos = temp.second.first;
		int x = client[pos][0], y = client[pos][1];
		int server = temp.second.second;
		if (sumCount[map[x][y]] > MAX_COUNT) {
			sumCount[map[x][y]]--;
			map[x][y] = server;
			sumCount[map[x][y]]++;
		}
		lev4.pop();
	}
}