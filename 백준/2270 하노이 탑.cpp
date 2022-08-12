#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

//2800KB	36ms

int diskPosition[100001];
int moveCountForMakeHanoi[100001];
int N, Result;
int MAX_COUNT = 1000000;

//하노이탑 로직
//현재 가장 큰 원판이 이동이 필요하다면
//현재 가장 큰 원판 위치, 목표위치를 제외한 1군데에 그 다음 큰 원판이 가장 밑인 하노이 탑을 만들어야 한다.

void hanoi(int disk, int target) {

	if (disk == 0) return;

	int now = diskPosition[disk];
	int next = target;
	if (now != target) {
		//여기서 더해지는 값은 현재 디스크를 옮기고 그거 보다 1개 작은 하노이의 탑을
		//그 디스크 위에 올리는 이동값이다.
		Result = (Result + moveCountForMakeHanoi[disk - 1]) % MAX_COUNT;

		for (int i = 1; i <= 3; i++) {
			if (now != i && target != i) {
				next = i;
				break;
			}
		}
	}

	//위에서 현재보다 1단계 작은 하노이탑을 현재 디스크 위에 올리는 것을 계산했으므로
	//이제는 1단계 작은 하노이탑을 만드는 것만 계산하면 된다.
	//1단계 작은 하노이탑을 만들 위치는 위의 하노이탑 로직을 참고
	hanoi(disk - 1, next);
}

void cal() {
	moveCountForMakeHanoi[0] = 1;
	for (int i = 1; i <= N; i++) {
		moveCountForMakeHanoi[i] = (moveCountForMakeHanoi[i - 1] * 2) % MAX_COUNT;
	}	
}

int main() {
	Result = 0;
	int pillar[3];
	cin >> N >> pillar[0] >> pillar[1] >> pillar[2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < pillar[i]; j++) {
			int k;
			cin >> k;
			diskPosition[k] = i+1;
		}
	}
	cal();
	hanoi(N, diskPosition[N]);
	//하노이의 탑은 한단계 더 옮기는게 2^n - 1 만큼의 횟수가 발생하기 때문에
	//가장 큰 원판이 있는 곳으로 옮기는 것이 횟수가 가장 적다
	cout << diskPosition[N] << '\n' << Result;
	return 0;
}
