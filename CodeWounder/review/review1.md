# 代码随想录复习

这个应该是title不是一级标题

# 数组

## 二分

while判断条件，我一般选择左闭右闭，搜索区间为【left，right】，模拟可以推断更新时left = middle-1，right = middle+1。

> ### 二分法第一种写法
>
> 第一种写法，我们定义 target 是在一个在左闭右闭的区间里，**也就是[left, right] （这个很重要非常重要）**。
>
> 区间的定义这就决定了二分法的代码应该如何写，**因为定义target在[left, right]区间，所以有如下两点：**
>
> - while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=
> - if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1
>
> 例如在数组：1,2,3,4,7,9,10中查找元素2，如图所示：
>
> ![704.二分查找](https://file1.kamacoder.com/i/algo/20210311153055723.jpg)

```cpp
// 版本一
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};
```

## 其他题目思路

- [x] 双指针，一个指针遍历，一个指针指向存放的位置

- [ ] 第一遍遍历到0，然后向两边扩散，分别比较负数平方和正数平方大小，先放小后放大。推荐做法应该是向中间遍历，大的数字填写在数组尾部。这是原地算法很常见的做法。
- [x] 滑动窗口，大就移动尾部，小向前移动头部
- [x] 旋转矩阵问题，需要确定循环不变量。此外此题目需要判断n为奇数的时候中心点需要填写（循环的时候步长尾n-1，最后一次无法填写）
- [x] 前缀和。一维和二维区间求和就是前缀和。

# 链表

写在最开头：链表数据结构定义

~~~cpp
// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
~~~

## 其他题目思路

- [x] 快慢指针，如果cur指向的是val，那么pre-》next = cur-〉next。一般情况下需要一个dummy节点，因为头节点可能也被删除

- [x] ```cpp
  ListNode *pre,*cur,*nxt;
  while(cur!=nullptr){
    nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
  }
  ```

- [x] 同样也是节点找规律

- [x] 删除倒数第N个，快慢指针，让快指针先走N步，此时慢指针对应的下一个节点就是需要删除的节点，直接 `slow.next =slow.next.next`

- [x] 一个指针同时开始走，记录步数，就是记录长度。然后让长的链表先走这个步数差，之后同时前进，第一相等节点就是焦点（地址相等）

- [x] 快慢指针，可以推理出slow和fast的步长差是一个环的长度

# 哈希表

说白了还是字典

## 其他题目思路

- [x] 《char，int》的字典，后面从字典里面扣词，如果词不够用或者有多余就是不行
- [x] 相同元素的数量，何尝不可以用动态规划（，但是这里用哈希表计算命中个数也是可以的
- [x] 按照函数计算一次之后就存储这个值，后面如果发现重复出现就是不可。
- [ ] 先对nums从小到大排序，从两侧移动，大了移动right，小了移动left。不可以直接sort，因为需要返回sort前数组的下标。所以这里的做法是《目标另一半的值，本身的下标》。如果nums【i】存在在哈希表里面，就直接返回查询到的结果，不存在插入哈希表。
- [ ] 四个数组的四数之和，拆分成两个数组的两数之和
- [x] 从magazine里面去满足ransom，无法满足就是false
- [ ] 此题目没有要求返回下标，先sort。先遍历一遍存储target-nums【i】的hash表，然后双循环遍历一遍。这里有的问题是nums中相同数字会重复出现。这里需要考虑去重的双指针，外循环移动起点：![15.三数之和](https://file1.kamacoder.com/i/algo/15.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.gif)
- [x] 先sort，然后双循环➕双指针。

# 字符串

## 常用的API

```c++
string s = to_string(1);
int a = stoi(s);
s = reverse(s.being(),s.end());
string ne = s.substr(pos,lenth);
```

## KMP算法

回答两个问题：next数组如何实现？next数组如何使用？

next数组存在的目的为：减少重复匹配工作。比如needle为aabaaf，那么我判断到f不一样，说明之前aa是一样的，这个可能是aab，那么我【aab】这部分就不用去从头匹配了。

next数组表示：当前下标-1的字串最大公公前后缀的位置，

```c++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> initNext(string needle) {
        int n = needle.size();
        vector<int> next(n, -1);
        int j = -1;
        for (int i = 1; i < n; i++) {
            while (j >= 0 && needle[j + 1] != needle[i])
            // j：当前判断的前缀的下标-1，如果j==-1，说明needle【0】也不满足要求；
            {
                j = next
                    [j];  // 当前前缀和needle【i】不一样，说明当前前缀下标-1和needle【i-1】是一样的
            }
            if (needle[j + 1] == needle[i]) j++;
            next[i] = j;
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        vector<int> next = initNext(needle);
        int i, j = -1;  // j表示需要判断的下标-1
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[j + 1]) {
                j++;
            } else {
                while (j >= 0 && haystack[i] != needle[j + 1]) {
                    j = next[j];
                }
                if (haystack[i] == needle[j + 1]) j++;
            }
            if (j == needle.size() - 1) return i - needle.size() + 1;
        }
        return -1;
    }
};
```



## 其他题目思路

- [x] 双指针向中间走，swap
- [x] for循环起点，步长是2k，reverse（s.begin()+i,s.begin()+i+k)。最后需要考虑提出的《k，<2k的特殊情况
- [x] 同样是已知目标输出长度，可以申请目标输出之后从后往前填写。双指针，一个从后往前遍历字符，一个从后往前填充目标输出
- [x] 尾部填充空格表示反转最后一个单词。双指针遍历，反转不是空格起点➕不是空格终点。然后寻找下一个不是空格起点
- [x] 旋转长度需要对字符串长度取余数。不过这道题目有一个特殊的解法是整体reverse之后，分成两段各自reverse
- [ ] 不用KMP的思路比较难想，对于重复子字符串的方法，通过头尾拼接得到一个2s中观察是否可以重新构筑s来判断。

# 双指针

## 代码随想录中这一部分都是其他的题目

# 栈和队列

## 其他题目思路

- [x] 两个栈，队列出队就倒到另一个栈

- [x] 出队入队，size为1的时候出去就是栈的输出

- [x] 左括号入栈，出现右括号如果1栈空2与栈顶种类不同则不匹配，遍历完毕栈不空不匹配

- [x] 与栈顶不同入栈，与栈顶相同出栈，最后应该string ans(stack.begin(),stack.end())就可以了。不过这里学到可以直接吧string当stack用

  ```c++
  class Solution {
  public:
      string removeDuplicates(string S) {
          string result;
          for(char s : S) {
              if(result.empty() || result.back() != s) {
                  result.push_back(s);
              }
              else {
                  result.pop_back();
              }
          }
          return result;
      }
  };
  ```

- [x] 逆波兰式求值，数字入栈符号出战运算后入栈

- [x] **单调队列**，其中队列需要维护一个从大到小的优先队列，每次移动滑动窗口之后需要判断优先队列中最大的那个数是否被踢出去了。这道题目应该用双头队列deque

- [ ] ![239.滑动窗口最大值-2](https://file1.kamacoder.com/i/algo/239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC-2.gif)

- [x] 优先队列，先sort之后计数长度，这个长度记录完毕之后存入优先队列，最后返回优先队列中前k个元素。这里优化的方案是构建一个大小为k的小顶堆，满了之后需要把最小的踢出去。此外这里发现还有一个地方是priority_queue传入的是class，重载运算符（），而sort传入的是一个static bool类型的函数。至于大小：默认是left《right构建一个递增序列，如果要改变就是left》right。

  ```c++
  class Solution {
  public:
      // 小顶堆
      class mycomparison {
      public:
          bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
              return lhs.second > rhs.second;
          }
      };
      vector<int> topKFrequent(vector<int>& nums, int k) {
          // 要统计元素出现频率
          unordered_map<int, int> map; // map<nums[i],对应出现的次数>
          for (int i = 0; i < nums.size(); i++) {
              map[nums[i]]++;
          }
  
          // 对频率排序
          // 定义一个小顶堆，大小为k
          priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
  
          // 用固定大小为k的小顶堆，扫面所有频率的数值
          for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
              pri_que.push(*it);
              if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                  pri_que.pop();
              }
          }
  
          // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
          vector<int> result(k);
          for (int i = k - 1; i >= 0; i--) {
              result[i] = pri_que.top().first;
              pri_que.pop();
          }
          return result;
  
      }
  ```

# 二叉树

首先是定义

```c++
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
```

层序遍历的时候，按经验说得先确认队列的size后用for循环，直接写不好写

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
```

## 其他题目思路

- [x] 交换左右孩子，然后递归处理左右孩子。一般用dfs即前序遍历的方法。

- [x] 反转root.right，然后递归比较root的左子树和右子树植是否相等。不过从层序遍历的角度来看只要看每一层是不是镜像的。

- [x] 递归，return max（dfs（left），dfs（right））+1；

- [x] int leftDepth = getDepth(node->left);
  int rightDepth = getDepth(node->right);
  int result = 1 + min(leftDepth, rightDepth);
  特别指出的是nullptr返回-1符合“深度”和“高度”之间的
  不同。

- [x] pow（2，height）-1。这里是完全二叉树不是满二叉树，这里可通过最大左深度和右深度是否相等来判断是否是满二叉树

- [x] 递归返回高度，如果失衡返回-1，最后看root递归结果是否是-1

- [x] 递归，pushback自己传入path，到nullptr存储path到最终答案，递归返回。非nullptr节点之后popback自己return，做回溯清理

- [x] 递归到 倒数第二层，判断是否是左叶子：root.left!=nullptr,root.left.left\==nullptr,root.left.right\==nullptr;

- [x] 层序遍历，如果新的队列为空，那么返回上一次队列的第一个入队的元素

- [x] 标准回溯算法，加入左子树，dfs左子树，pop左子树，加入右子树，dfs右子树，pop右子树。在这个过程中观察是否满足要求，满足就加入ans

- [x] 后续最后一个是根节点，找到中序中这个节点的位置，这时候可以推断出左右子树的长度root.left = (中序左子树起点终点，后序左子树起点终点)，right部分同理。确认为左闭右闭

- [x] 寻找最大数的下标，然后递归遍历起始位置终止位置，依然选择左闭右闭

- [x] 以Tree1作为要返回的值，同步遍历，两非空就相加，Tree1空Tree2非空就new新节点，Tree1非空Tree2空不处理，两空不用处理

- [x] 比root大往右走，比root小往左走，找到返回节点，没找到返回nullptr

- [x] return 当前节点是否满足搜索树定义&&左子树是否满足&&右子树是否满足，nullptr对应的应该是满足，如果子树不存在默认这一侧满足。或者中序遍历是否是单调递增数组

- [ ] 最小绝对差只会出现在root-root.left,root.right-root这两个前提下。这也能做，但是有一个很重要的思想是递归中的pre和cur双指针

- [x] 同样也是双指针，这里有一个

  ```c++
  if (count > maxCount) { // 如果计数大于最大值频率
      maxCount = count;   // 更新最大频率
      result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
      result.push_back(cur->val);}
  ```

  的技巧，我在别的地方也见到过。

- [x] 递归判断当前节点是否是q或者p，如果是空，返回false，然后判断左子树和右子树是否含有q或者p。如果当前节点是q或者p，子树中又含有q或者p，那么第一次满足的就是正确答案。如果左子树含有q或者p，右子树含有q或者p，第一次满足时就是正确答案。其余情况返回自己是｜｜左子树含有｜｜右子树含有。

注明：这里当时五一开始之后，去写贪心和动态规划，树从第28片开始，然后回溯算法先跳过了，后面需要记得写

# 贪心

## 其他题目思路

- [x] g，s都排序，然后用最接近的满足孩子的需求。index指向最小的胃口，遍历从最小的饼干开始
- [ ] 记录峰值点的个数。开头结尾的点也算作峰值点。这里需要特别注意相等不算峰值点，所以双指针的一个遍历条件是》=。完全上升点也只能算一次。建议有机会重新写一遍考虑边界条件
- [x] 这种题目贪心和动态规划一体两面。我还是认为用dp【i】表示以nums【i】结尾的子数组最大和，需要加一个result，在更新dp数组的时候更新最大的result。如果是贪心就是发现求和小与0之后果断用自己作为值
- [x] 利润可以拆分为每一天的利润，所以我们只需要把正数利润加起来就可以了。从动态规划的角度来看就是持有股票和不持有股票的最大收益，由于可以多次交易，所以持有股票状态可以是当日不持有股票最大收益购入股票
- [x] 遍历更新可到达最远位置，fast = i+step【i】，最后看最远位置和数组长度之间的关系
- [x] 每次更新最远跳跃位置，在当前段最远跳跃位置选举下一个最远跳远位置。选举次数就是最远跳跃步数
- [x] 先sort，对于负数使用N次反转机会，之后还有K-N次翻转，这个时候看下是最小正数小还是最大负数小，偶数不影响，奇数减去abs，之后继续求和
- [ ] 做起来还是有一定猜的成分在，就是**当前累加rest[i]的和curSum一旦小于0，起始位置至少要是i+1，因为从i之前开始一定不行**。【-4，-3，1，2】更新起点，更新区间累加和，全局累加和不清空，因为不管从哪个起点开始累加和都是一样的
