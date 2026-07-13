#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class MyQueue {
    stack<int> inStack;
    stack<int> outStack;

   public:
    MyQueue() {
        inStack = stack<int>();
        outStack = stack<int>();
    }

    void push(int x) { inStack.push(x); }

    int pop() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
        int re = outStack.top();
        outStack.pop();
        while (!outStack.empty()) {
            inStack.push(outStack.top());
            outStack.pop();
        }
        return re;
    }

    int peek() {
        if (!outStack.empty())
            return outStack.top();
        else {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
            int onTop = outStack.top();
            while (!outStack.empty()) {
                inStack.push(outStack.top());
                outStack.pop();
            }
            return onTop;
        }
    }

    bool empty() { return inStack.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */