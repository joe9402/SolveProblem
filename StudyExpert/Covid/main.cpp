#include<stdio.h>
#include <ctime>
#define MAX_DATA 50000000
#define VIRUS 50000

int tray[MAX_DATA * 2];

double SCORE = 0;
unsigned int seed = 3;
extern void test();

int check_up(int idx) {
    SCORE += 1.;
    if (idx < 0 || MAX_DATA * 2 < idx) return tray[0];

    return tray[idx];
}

void culture(int n, int a, int b) {
    if (n < MAX_DATA || MAX_DATA * 2 < n) return;
    if (a < 0 || MAX_DATA * 2 < a) return;
    if (b < 0 || MAX_DATA * 2 < b) return;
    tray[n] = tray[a] | tray[b];
}

void clear(int idx) {
    SCORE += 10.;
    if (idx < 0 || MAX_DATA < idx) return;
    tray[idx] = 0;
}

unsigned int random() {
    return seed = (seed * 25214903917ULL) + 11ULL;
}

int main() {
    for (int i = 0; i < MAX_DATA * 2; ++i) {
        tray[i] = 0;
    }
    int idx;
    for (int i = 0; i < VIRUS; ++i) {
        idx = random() % MAX_DATA;
        tray[idx] = 1;
    }
    clock_t Time = clock();
    test();
    for (int i = 0; i < MAX_DATA; ++i) {
        if (tray[i] == 1) {
            SCORE += 10000.;
        }
    }
    SCORE += (clock() - Time) / 100000.;
    printf("SCORE = %.5f\n", SCORE);
}