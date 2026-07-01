#include <iostream>
// #include <stack>
#include <stack>
#include <vector>
using namespace std;
class MinStack {
    stack<int> _minStack, myStack;

   public:
    MinStack() {
        myStack = stack<int>();
        _minStack = stack<int>();
        // cout << "init" << endl;
        //  temp = stack<int>();
    }

    void push(int value) {
        myStack.push(value);
        stack<int> temp;
        while (!_minStack.empty()) {
            if (_minStack.top() < value) {
                temp.push(_minStack.top());
                _minStack.pop();
            } else
                break;
        }
        _minStack.push(value);
        while (!temp.empty()) {
            _minStack.push(temp.top());
            temp.pop();
        }
        // cout << "push" << endl;
    }
    int top() {
        // cout << "top" << endl;
        return myStack.top();
    }
    void pop() {
        int top = this->top();
        myStack.pop();
        stack<int> temp;
        while (!_minStack.empty() && _minStack.top() != top) {
            temp.push(_minStack.top());
            _minStack.pop();
        }
        _minStack.pop();
        while (!temp.empty()) {
            _minStack.push(temp.top());
            temp.pop();
        }
        // cout << "pop" << endl;
    }

    int getMin() {
        // cout << "getMin" << endl;
        return _minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */