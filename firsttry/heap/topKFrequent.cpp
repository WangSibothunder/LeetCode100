#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
    void maxHeapify(vector<pair<int, int>> &nodes, int i, int heapsize)
    {
        int leftChild = i * 2 + 1, rightChild = i * 2 + 2, largest = i;
        if (leftChild < heapsize && nodes[leftChild].second > nodes[largest].second)
        {
            largest = leftChild;
        }
        if (rightChild < heapsize && nodes[rightChild].second > nodes[largest].second)
            largest = rightChild;
        if (i != largest)
        {
            swap(nodes[i], nodes[largest]);
            maxHeapify(nodes, largest, heapsize);
        }
    }
    void buildHeap(vector<pair<int, int>> &nodes, int heapsize)
    {
        for (int i = heapsize / 2 - 1; i >= 0; i--)
        {
            maxHeapify(nodes, i, heapsize);
        }
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        vector<pair<int, int>> nodes;
        for (auto &c : nums)
        {
            map[c]++;
        }
        for (auto &kv : map)
        {
            nodes.push_back(kv);
        }
        int heapsize = nodes.size();
        buildHeap(nodes, heapsize);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(nodes[0].first);
            swap(nodes[0], nodes[heapsize - 1]);
            --heapsize;
            maxHeapify(nodes, 0, heapsize);
        }
        return ans;
    }
};