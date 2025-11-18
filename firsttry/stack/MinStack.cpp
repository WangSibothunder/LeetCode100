#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> my_stack;
    stack<int> min_stack;

public:
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int val)
    {
        my_stack.push(val);
        if (val <= min_stack.top())
            min_stack.push(val);
    }

    void pop()
    {
        int temp = my_stack.top();
        my_stack.pop();
        if (temp == min_stack.top())
            min_stack.pop();
    }

    int top()
    {
        return my_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */