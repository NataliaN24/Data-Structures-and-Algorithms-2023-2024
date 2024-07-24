#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

class Median
{
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:
    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() )
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Median median;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        median.addNum(num);
        cout << fixed << setprecision(1) << median.findMedian() << endl;
    }
}
