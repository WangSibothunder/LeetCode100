#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        int area = 0;
        stack<int> minStack;
        for (int i = 0; i < height.size(); i++) {
            while (minStack.size() > 1 && height[i] > height[minStack.top()]) {
            }
        }
    }
};