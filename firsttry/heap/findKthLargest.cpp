#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    void maxHeapify(vector<int> &a, int i, int heapsize)
    {
        int leftChild = i * 2 + 1, rightChild = i * 2 + 2, largest = i;
        if (leftChild < heapsize && a[leftChild] > a[largest])
            largest = leftChild;
        if (rightChild < heapsize && a[rightChild] > a[largest])
            largest = rightChild;
        if (largest != i)
        {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapsize); // 更新所有子树
        }
    }
    void buildMaxHeap(vector<int> &a, int heapsize)
    {
        for (int i = heapsize / 2 - 1; i >= 0; i--)
        {
            maxHeapify(a, i, heapsize);
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int heapsize = nums.size();
        buildMaxHeap(nums, heapsize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            heapsize--;
            maxHeapify(nums, 0, heapsize); // 从根节点开始构建
        }
        return nums[0];
    }
};