extern int check_up(int idx);
extern void culture(int n, int a, int b);
extern void clear(int idx);
#include <iostream>
#define MAX_DATA 50000000
#define PART_AREA 600
#define CHECK_POINT 50002000
/*
PART_AREA = 1024
SCORE = 1077631.02059
check : 577871  clear : 49976   fail : 0

PART_AREA = 512
SCORE = 1074331.01446
check : 574571  clear : 49976   fail : 0
*/

int startPoint;

bool checkArea(int l, int r) {
	culture(CHECK_POINT + 1, CHECK_POINT + 2, CHECK_POINT + 3);
	for (int i = l; i <= r; i++) {
		culture(CHECK_POINT + 1, CHECK_POINT + 1, i);
	}
	return check_up(CHECK_POINT + 1);
}

void binarySearch(int l, int r) {
	int m = (l + r) / 2;
	if (l >= r) {
		clear(l);
		startPoint = l;
	}
	else {
		if (checkArea(l, m)) {
			binarySearch(l, m);
		}
		else {
			binarySearch(m+1, r);
		}
	}
}

void test() {
	startPoint = 0;
	while (startPoint < MAX_DATA) {
		if (checkArea(startPoint, startPoint + PART_AREA)) {
			binarySearch(startPoint, startPoint + PART_AREA);
		}
		else {
			startPoint += PART_AREA;
		}
	}
}