#include <iostream>
#include <vector>

using namespace std;

class MedianFinder {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : ((double)store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};

int main() {
    MedianFinder a = MedianFinder();
    a.addNum(1);
    a.addNum(2);
    printf("%f\n",a.findMedian());
    a.addNum(3);
    printf("%f\n", a.findMedian());
    a.addNum(4);
    printf("%f\n", a.findMedian());


    
}