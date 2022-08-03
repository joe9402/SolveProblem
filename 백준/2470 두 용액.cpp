#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

/*int main() {
    int N;
    vector<int> v;
    cin >> N;
    string res = "";
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());

    if (N == 2 || v[0] > 0) {
        cout << v[0] << " " << v[1];
        return 0;
    }
    if (v[v.size() - 1] < 0) {
        cout << v[v.size() - 2] << " " << v[v.size() - 1];
        return 0;
    }

    int min = 2000000000;
    int i = 0;
    while (i < N-1) {
        int j;
        if(v[i] < 0)
             j = v[i] * -1;
        else j = v[i] +1;
        int k = lower_bound(v.begin(), v.end(), j) - v.begin();
        int sum;
        if (k >= 0 && k < N && k != i) {
            sum = abs(v[i] + v[k]);
            if (min > sum) {
                res = to_string(v[i]) + " " + to_string(v[k]);
                min = sum;
                if (sum == 0) {
                    cout << res;
                    return 0;
                }
            }
        }
        if (k - 1 >= 0 && k - 1 < N && k-1 != i) {
            sum = abs(v[i] + v[k-1]);
            if (min > sum) {
                res = to_string(v[i]) + " " + to_string(v[k-1]);
                min = sum;
                if (sum == 0) {
                    cout << res;
                    return 0;
                }
            }
        }
        //cout << i << " "  << k << " "  << v[i] << " " << j << " " << min << " " << res << endl;
        i++;
    }
    cout << res;
}*/

int main() {
    int N;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());

    if (N == 2 || v[0] > 0) {
        cout << v[0] << " " << v[1];
        return 0;
    }
    if (v[v.size() - 1] < 0) {
        cout << v[v.size() - 2] << " " << v[v.size() - 1];
        return 0;
    }

    int min = 2000000000;
    int l = 0, r = N-1;
    string res = "";
    while (l < r) {
        if (l >= N || r < 0) break;
        int now = v[l] + v[r];
        if (min > abs(now)) {
            min = abs(now);
            res = to_string(v[l]) + " " + to_string(v[r]);
        }
        if (now < 0) {
            l++;
        }
        else
            r--;
    }

    cout << res;
}