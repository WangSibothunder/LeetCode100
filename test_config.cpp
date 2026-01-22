#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // 测试STL容器的自动补全
    cout << "Vector size: " << nums.size() << endl;
    
    // 测试字符串操作的自动补全
    string str = "Hello, IntelliSense!";
    cout << "String length: " << str.length() << endl;
    
    // 测试算法的自动补全
    reverse(nums.begin(), nums.end());
    
    return 0;
}