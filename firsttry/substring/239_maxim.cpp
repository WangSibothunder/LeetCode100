#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> nums = {1};

    int k = 3;

    pair<int, int> temp; // 《下标，数值》
    vector<int> ans;
    int max_num = nums[0], max_index = 0;
    // vector<int> temp;
    int len = 0;
    for (int i = 0; i < k - 1; i++)
    {
        if (max_num <= nums[i])
        {
            max_index = i;
            max_num = nums[i];
        }
    }
    temp = make_pair(max_index, max_num);
    ans.push_back(max_num);
    int head_index, head_value;
    for (int i = k - 1; i < nums.size(); i++)
    {
        head_index = temp.first;
        head_value = temp.second;
        if (head_index < i - k)
        { // 最大值丢失，寻找新最值
            max_num = nums[i];
            for (int j = i-k+1; j <=i ; j++)
            {
                if (max_num <= nums[j])
                {
                    max_index = j;
                    max_num = nums[j];
                }
            }
            temp = make_pair(max_index, max_num);
            printf("最大值丢失，更新段落最大坐标%d,最大值%d\n",max_index,max_num);
            ans.push_back(max_num);
        } 
        else if(head_value<=nums[i]){//未丢失，出现新的最值
            ans.push_back(nums[i]);
            temp = make_pair(i, nums[i]);
            printf("最大值改变，段落最大坐标%d,最大值%d\n",i,nums[i]);
        }
        else{ 
            printf("最大值不变，段落最大坐标%d,最大值%d\n",head_index,head_value);
            ans.push_back(head_value);}
    }

    return 0;
}