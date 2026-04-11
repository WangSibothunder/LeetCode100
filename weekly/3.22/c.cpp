#include <iostream>       // 提供输入输出功能（cout 等）
#include <unordered_map>  // 提供哈希表 unordered_map
#include <vector>         // 提供动态数组 vector
using namespace std;      // 使用标准命名空间，省去 std:: 前缀

class Solution {                                      // 定义题解类
   public:                                            // 公有成员，外部可调用
    int minRemovals(vector<int>& nums, int target) {  // 返回最少删除次数
        int totalXor = 0;                             // 记录整个数组的异或和
        for (int x : nums) totalXor ^= x;             // 计算 nums 所有元素异或

        // 需要删除的子集异或值：delXor = totalXor ^ target
        int need = totalXor ^ target;  // 目标删除子集 xor

        // dp[x] = 得到异或和 x 时，最少删除了多少个元素
        unordered_map<int, int> dp;  // 当前阶段 DP 状态
        dp.reserve(2048);            // 预留空间，减少哈希扩容开销
        dp[0] = 0;                   // 初始状态：不删元素，xor=0，代价=0

        for (int x : nums) {  // 逐个处理数组元素
            unordered_map<int, int> next =
                dp;  // 先复制一份：表示“不删除当前元素”
            next.reserve(dp.size() * 2 + 8);  // 预留更多空间，减少扩容

            for (const auto& [xorVal, cnt] :
                 dp) {                // 枚举旧状态：xorVal 与其最小删除数 cnt
                int nx = xorVal ^ x;  // 若删除当前元素，新的 xor 值
                auto it = next.find(nx);  // 查看 next 中是否已有该 xor 状态
                if (it == next.end() ||
                    cnt + 1 < it->second) {  // 没有或找到更优解
                    next[nx] = cnt + 1;      // 更新：删除当前元素，代价 +1
                }
            }
            dp.swap(next);  // 本轮结束，next 成为新的 dp
        }

        auto it = dp.find(need);  // 查找是否能达到目标删除 xor
        return it == dp.end()
                   ? -1
                   : it->second;  // 能达到返回最小删除数，否则返回 -1
    }
};

int main() {                                 // 本地调试入口
    vector<int> nums = {7};                  // 测试数组
    int target = 7;                          // 目标异或值
    Solution sol;                            // 创建解题对象
    int re = sol.minRemovals(nums, target);  // 调用函数求解
    cout << re << endl;                      // 输出结果
    return 0;                                // 程序正常结束
}
