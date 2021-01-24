#include <iostream>
#include <vector>

using namespace std;

class MedianFinder {
    vector<int> a; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (a.empty())
            a.push_back(num);
        else
            a.insert(lower_bound(a.begin(), a.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int size = a.size();
        if (size % 2)return a[size / 2];
        else return (double)(a[size / 2] + a[size / 2 - 1]) / (double)2;
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