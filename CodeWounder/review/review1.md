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
- [ ] 每次都是最低程度满足。先从左往右遍历一遍，如果右边的比左边高，右边就比左边的孩子多一颗糖。如果右边比左边低就只给一颗。然后从右往左遍历，左边比右边高，左边就应该多给一颗。然后去第一次遍历的值和这个的max。我认为这是一个非常巧妙的思想，还有一种采用这种寻找两边信息的是借雨水问题。
- [x] 一道经典的贪心，最主要的是能找零10r就给10r，5r作为万金油必须最后再使用
- [ ] 这道题目第一编做比较难想到。先用身高作为第一关键字从高到低排序，再用前面有多少人作为第二关键字从低到高排序。这样在遍历时，第二关键字就作为在答案中需要插入的下标。这个时候ans数组可以用list作为底层容器`list<vector<int>> `从贪心的视角想，我们每次都满足插入的那个人的信息是对的，从全局来说就是全局最优🟰局部最优
- [x] 箭射气球问题，这一题需要发现从中间开始找地方射气球和从左往右遍历最优的射气球是一样的。对气球的起始位置进行排序。开始选中第一个气球，记录右端点，遍历下一个气球，如果气球左端点在记录的右端点之内，继续遍历下一个。如果发现气球的左端点超过记录的右端点，那么箭数量++，然后选取这个气球记录他的右端点，依次如此。
- [x] 可以发现，最大无重叠区间的数量必然是从最左端开始的那个线段开始的。因为假设最大无重叠区间开始的那个区间左端在最左端开始的线段右端点之外，答案肯定可以加上第一个线段。所以sort左端点，然后取左端点在第一个线段的区间之内的所有线段，统计首尾没有交集线段的数量，取最大值。需要删除线段的数量是size-max。题解给的方案是按照右区间排序之后，每次取下一个合法右区间的线段，比我想的简单些
- [x] 我记得我第一遍用大模拟法做的，做的比较复杂但是毕竟思路就是向前合并。这里很聪明的解法是第一编遍历记录字符最后一次出现的位置，第二次遍历进行分割，遍历取最大值，如果最大值下标等于下标就是切分点，确认切分点之后最大值下标归零进行下一轮循环。anyway，考试的时候没想到这么巧的方法能用大模拟写出来的能力还是很重要的。
- [x] sort左端点，遍历合并，不过这里有一个case就是右端点应该取max而不是直接赋值。类箭射气球。
- [x] 对于1位，直接返回，对于多位，如果pre》cur就保留，出现pre《cur的情况，cur-1，后面所有位变成0；或者说从出现cur-1开始后面就是9.那么从左往右遍历也是可以的。
- [ ] dfs，遍历到最底层的上一层，子节点没安装，父节点安装。因为父节点至少可以服务四个节点（考虑本身），因此优先给父节点安装。如果左右孩子都覆盖了，那么父节点返回上一父节点请求安装。情况比我想的多，建议手写。

# 动态规划

## 其他题目思路

- [x] F1，f2，f3来回更新

- [x] f[i] = f[i-1]+f[i-2],如果有m中跳跃补偿就遍历这个步长数组求和

- [x] dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]),其中dp【i】表示为到达下标为i的台阶需要花费的最小体力，初始化全为零，从i=2开始往后面遍历。

- [x] dp【i，j】 = dp【i-1，j】+ dp【i，j-1】。这里初始化可以初始化一个m+1，n+1的数组，然后设置dp【0，1】 = 1，后面开始遍历比较方便。

- [x] 可以标记障碍物为INT_MIN,然后后面对递推的时候max和0判断下

- [x] dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));不过我自己推导的时候还是继续切分了dp[i-j] * dp[j]还有i * (i-j)

- [ ] 我推断出来的方法是：新的节点作为头节点：左子树有dp【i-1】种。新的节点作为叶子节点，可以作为dp【i-1】个树的叶子，作为中间节点退出来不是很确定。看了题解发现还是对二叉搜索树理解的不够深入，可以遍历根节点选择，左子树之有比他小的选择，右子树之有比他大的选择。对于一共i个数第j个点：dp[i] =dp[i]+ dp[j-1]*dp[i-j]

- [x] 问题转换：求和数组得到sum，然后就是问你是否可以选择出恰好等于sum/2的子集（sum是奇数的话直接pass）。后面可以写出01背包的递推公式。需要指出的是，提交时候要记得去掉日志，不然会超时。

- [x] 这里可以依然分成两组，求和到sum/2+1.最后应该和sum做差，就是最大的结果，需要考虑奇偶。题目解下来发现不需要考虑奇偶，可以直接用`(sum - max_index) - max_index`

- [ ] 有些蹊跷在，我在想是否需要计算前缀和之后，取负用-两倍表示。问题可以转化为：从nums数组中取出一个总和是（sum-targe）/2子集有多少种取法。这种题目纯巧妙，做过一次才知道。此外这里需要考虑数组中会存在0，

- [x] 我认为是三维dp，将0的数量和1的数量分别作为一个纬度，然后递推`dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1)`，不过这里用原来的一维数组优化了，所以不是三维。

- [x] `dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]]`，初始化`dp[i][0] = 1`，所有硬币中之和=0的方法有一种。需要指出的是本题问的是组合数，所以可以直观的采用先选物品在判断值，若是排列数，需要先遍历值再去选择物品。（在用一维dp的时候）

- [x] 可重复选择的目标和，`dp[i][j] = dp[i-1][j]+dp[i][j-nums[i]]`，然后`dp[i][0]=1`进行初始化。

- [x] for循环，有之前1-m步的方法，全都加起来。初始化f【0】 = 1，因为后面用减法取上一次的方法

- [x] 完全背包问题，此外应INT_MAX/2初始化，用min判断是否是可以组合

- [x] 可枚举选项从1，4一直到sqrt（n）^2，然后应该是`dp[i][j] = min(dp[i-1][j],dp[i][j-(i^2)]+1)`,初始化为INT_MAX/2，dp【i】【0】=0，最后输出dp【i】【n】，因为1一定可以满足要求，所以可以直接返回。

- [x] 外循环遍历字母，内循环遍历可选单词。这里可以简单的用dp【i】，因为只要一个单词满足这个状态就是满足的。

- [x] `dp[i] = max(dp[i-1],dp[i-2]+values[i-1])`偷或者不偷，这里会有一个初始化问题，第一个房子和第二个房子的dp应该都是他们本身的价值

- [x] 环形打家劫舍，把一个环拆分两个，一个是从第一个房子到第n-1个房子做打家劫舍，一个是从第二个房子到第n个房子做打家劫舍。

- [ ] 树形dp，这道题目有机会还是动手做一下比较好。递归返回的应该是：【子树收益，选根的收益】。子树收益为`max(dfs（左子树）【选根收益】,【子树收益】）,+ max(dfs（右子树）【选根收益】，【子树收益】)`（这里体现出来dp）；选根收益为`根的值+dfs（左子树）【子树收益】+dfs（右子树）【子树收益】`，此外对于最后一层，返回应该是【0，自己的值】，因为0参与后续运算没有影响。

- [x] 基础版本买卖股票只能交易一次。循环遍历，1记录最小值，2.记录做差最大值，每次得到新的数之后更新最小值和做差手得到的最大值。

- [x] ```cpp
  dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i-1]);//不持有股票的最大收益
  dp[i][1] = max(dp[i-1][1],dp[i][0]-prices[i-1]);//不持有股票的最大收益，当天卖出之后应该允许买入
  ```

- [ ] 188.买卖股票的最佳时机IV。这道题目值得代码练习。最多只能进行m次交易，为了简化代码我们可以把第二个纬度改为`2*（m+1）`，其中`dp[i][2*j]和dp[i][2*j+1]`表示第j次操作时不持有/持有股票的最大收益，这里定义卖出才是一次操作。初始化的时候，第0天不允许持有股票的行为。外循环遍历天数，内循环遍历交易次数，有点背包问题的视角。

- [ ] 多状态dp，需要写出并推导状态转移。看到题目5min没有思路。

- [x] 我们认为卖出的时候付手续费，所以卖出收益就是`dp[i-1][1]+prices[i-1]-fee`

- [x] 令dp【i】表示以nums【i】结尾的子集的最大长度。需要进行两次循环，第一次循环选择i，第二次循环选择可以让nums【i】加入的，目前最长的子集下标j。

- [x] 令dp【i】表示以nums【i】结尾的子集的最大长度。若nums【i】小于等于nums【i-1】，dp【i】 = 1否则就是在之前的长度加一。遍历的时候，记录目前的最大长度result。

- [x] dp【i】【j】表示以a【i】和b【j】结尾的子串中能达到的最大相同长度。递推关系时
  ```cpp
  if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
  else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
  ```

- [x] 与上文递推关系式一致，不过上题题解里面没有max更新那一步

- [x]  这不过就是最大相同子字符长度，与上一题的代码应该是一模一样的

- [x] `dp[i] = max(nums[i],dp[i-1]+nums[i])`

- [x] ```cpp
  if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1];
  else dp[i][j] = dp[i][j-1];
  //初始化dp[0][j] = 1当s是空串的时候必然是满足的
  ```

- [x] ```cpp
  if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
  else dp[i][j] = dp[i][j-1];
  遍历顺序来说，外循环遍历t子串，内循环遍历s的子串
  ```

- [x] ```cpp
  if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1];//不需要操作
  else dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;//相对“j没有出现”来说需要多一个删除操作
  初始化的时候dp[0][j]可以全部初始化为1
  ```

- [ ] 编辑距离这题比较经典，我认为值得上手做一遍。值得注意的是，对于插入和删除操作，我们可以将a的插入操作等价于b的删除操作（都是消除一个不匹配的，其他元素不受影响）

- [ ] 这里有个编程上的技巧，用一个独立变量result去记录总数量，然后用bool标记这个区间是否是回文。i倒序循环，值得上手做一遍。

- [ ] 如果`s[i]==s[j]`，那么最长回文序列长度是`dp[i+1][j-1]+2`，否则就是`max(dp[i+1][j],dp[i][j-1])`这里依然需要一个i倒序循环。

# 图论

## 并查集

我们需要一种数据结构来判断两个元素是否在同一个集合中，以及如何将两个元素加入一个集合。

```cpp
int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
vector<int> father = vector<int> (n, 0); // C++里的一种数组结构
// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u) {
    if (u == father[u]) return u;
    else return father[u] = find(father[u]); // 路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[u] = v;
}
```

## prim算法（无向图的最短联通）

1. 第一步，选距离生成树最近节点
2. 第二步，最近节点加入生成树
3. 第三步，更新非生成树节点到生成树的距离（即更新minDist数组）

```cpp
#include<iostream>
#include<vector>
#include <climits>

using namespace std;
int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    // 填一个默认最大值，题目描述val最大为10000
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
    while (e--) {
        cin >> x >> y >> k;
        // 因为是双向图，所以两个方向都要填上
        grid[x][y] = k;
        grid[y][x] = k;

    }
    // 所有节点到最小生成树的最小距离
    vector<int> minDist(v + 1, 10001);

    // 这个节点是否在树里
    vector<bool> isInTree(v + 1, false);

    // 我们只需要循环 n-1次，建立 n - 1条边，就可以把n个节点的图连在一起
    for (int i = 1; i < v; i++) {

        // 1、prim三部曲，第一步：选距离生成树最近节点
        int cur = -1; // 选中哪个节点 加入最小生成树
        int minVal = INT_MAX;
        for (int j = 1; j <= v; j++) { // 1 - v，顶点编号，这里下标从1开始
            //  选取最小生成树节点的条件：
            //  （1）不在最小生成树里
            //  （2）距离最小生成树最近的节点
            if (!isInTree[j] &&  minDist[j] < minVal) {
                minVal = minDist[j];
                cur = j;
            }
        }
        // 2、prim三部曲，第二步：最近节点（cur）加入生成树
        isInTree[cur] = true;

        // 3、prim三部曲，第三步：更新非生成树节点到生成树的距离（即更新minDist数组）
        // cur节点加入之后， 最小生成树加入了新的节点，那么所有节点到 最小生成树的距离（即minDist数组）需要更新一下
        // 由于cur节点是新加入到最小生成树，那么只需要关心与 cur 相连的 非生成树节点 的距离 是否比 原来 非生成树节点到生成树节点的距离更小了呢
        for (int j = 1; j <= v; j++) {
            // 更新的条件：
            // （1）节点是 非生成树里的节点
            // （2）与cur相连的某节点的权值 比 该某节点距离最小生成树的距离小
            // 很多录友看到自己 就想不明白什么意思，其实就是 cur 是新加入 最小生成树的节点，那么 所有非生成树的节点距离生成树节点的最近距离 由于 cur的新加入，需要更新一下数据了
            if (!isInTree[j] && grid[cur][j] < minDist[j]) {
                minDist[j] = grid[cur][j];
            }
        }
    }
    // 统计结果
    int result = 0;
    for (int i = 2; i <= v; i++) { // 不计第一个顶点，因为统计的是边的权值，v个节点有 v-1条边
        result += minDist[i];
    }
    cout << result << endl;

}

```

## dijkstra（有向图的最短联通）







## 其他题目思路

- [x] 最大岛屿面积：bsf的时候计数，计数完和预备答案比大小选大的。
- [x] 岛屿面积加起来
- [x] 我怎么感觉从【2，2】搜索到【n-1,m-1】就可以了？或者说就按着四边遍历进行bfs，最后一遍遍历有1单不是四边染色到的就是我们不选择的
- [ ] 这道题目很有技巧，正难则反，用逆流而上考虑，我认为比较有挑战
- [x] 第一次遍历计算每个岛屿面积，第二次遍历的时候把这个块和他接壤的四个块（如果有岛的话）面积加在一起。每次取最大值。我在想如何确认一个点对应的岛屿的面积，我认为可以bfs两次。第一次bfs确认面积，第二次bfs填写面积。
- [x] 没有水的那个方向周长+1
- [x] 建图，应该先判断哪些字符串是可以通过一步转化得到。然后bfs
- [x] 从1号节点开始bfs，染色一个未访问节点就++，最后将count与n比较，一样大说明都访问到了。
- [x] 如果从并查集的角度想，从根出发，相连的节点join在一起，最后看isSame起点和终点。
- [x] 对于一个新的节点，先看是否不是isSame，如果不是就join进去，如果isSame了说明已经连接过了，就是false。
- [ ] 判断入度是否为2和是否存在有向环，这种题目都有一定难度。
- [x] 拓扑排序，统计入度，配置一个入度为0的队列。出队，更新新的入度，入度为0的点出队列。出对顺序就是处理顺序。如果出队数量小于节点数就是存在环。
- [x] 
