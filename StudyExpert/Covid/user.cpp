extern int check_up(int idx);
extern void culture(int n, int a, int b);
extern void clear(int idx);
#include <iostream>
#define MAX_DATA 50000000
#define VIRUS 50000
#define NodeCount 4

//NodeCount : 2
//SCORE = 1506319.01837
//chear : 49976  check : 1006559  fail : 0

//NodeCount : 3
//SCORE = 1424551.01393
//chear : 49976  check : 924791  fail : 0

//NodeCount : 4
//SCORE = 1456246.01216
//chear : 49976  check : 956486  fail : 0


int maxPoint;

bool checked[MAX_DATA] = { false };

void makeBinary() {
	for (int i = 0; i < (MAX_DATA - 1); i++) {
		//culture(i + MAX_DATA, 2 * i, 2 * i + 1);
		if (i + MAX_DATA > NodeCount * i + (NodeCount - 1)) {
			maxPoint = i + MAX_DATA;
			for (int j = 0; j < NodeCount; j++) {
				culture(i + MAX_DATA, i + MAX_DATA, NodeCount * i + j);
			}
		}
		else {
			break;
		}
	}
}

void checkBinary(int a) {
	int piv = a - MAX_DATA;
	if (piv < 0) {
		if (check_up(a)) clear(a);
	}
	else {
		if (checked[piv]) {}
		else {
			checked[piv] = true;
			if (check_up(a)) {
				//checkBinary(2*piv);
				//checkBinary(2*piv + 1);
				for (int j = 0; j < NodeCount; j++) {
					checkBinary(piv * NodeCount + j);
				}
			}
		}
	}
}


void test() {
	maxPoint = 0;
	makeBinary();
	//checkBinary(2* MAX_DATA-2);
	for (int i = 0; i < NodeCount; i++) {
		checkBinary(maxPoint - i);
	}

}