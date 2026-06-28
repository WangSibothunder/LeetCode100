#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Bigger {
   public:
    bool operator()(int& a, int& b) { return a < b; }
};
class Smaller {
   public:
    bool operator()(int& a, int& b) { return a > b; }
};
class MedianFinder {
    int pivot = INT_MIN;
    int mid = 0;
    int nums = 0;
    priority_queue<int, vector<int>, Smaller> pqueue;
    priority_queue<int, vector<int>, Bigger> mqueue;

   public:
    MedianFinder() {
        nums = 0;
        mid = 0;
        pivot = INT_MIN;
        pqueue = priority_queue<int, vector<int>, Smaller>();
        mqueue = priority_queue<int, vector<int>, Bigger>();
    }
    void addNum(int num) {
        if (nums == 0) {
            mid = num;
            pivot = num;
            mqueue.push(num);  // 第一个数放左侧队列
        } else {
            if (num <= mqueue.top()) {  // 需要新加入在左半队列
                if (nums % 2) {  // 有奇数个数，加入之后需要弹到右侧队列一个
                    mqueue.push(num);
                    pqueue.push(mqueue.top());
                    mqueue.pop();
                } else {  // 有偶数个，放在左侧队列的话也合法
                    mqueue.push(num);
                }
            } else {  // 需要新加入在右侧队列
                if (nums % 2) {
                    pqueue.push(num);
                } else {
                    pqueue.push(num);
                    mqueue.push(pqueue.top());
                    pqueue.pop();
                }
            }
        }
        nums++;
    }

    double findMedian() {
        if (nums % 2)
            return mqueue.top();
        else {
            return (double(pqueue.top()) + double(mqueue.top())) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */