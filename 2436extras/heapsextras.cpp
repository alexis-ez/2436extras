// 347. Top K Frequent Elements - leetcode medium
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        for (pair<const int, int>& p : freqMap) {
            buckets[p.second].push_back(p.first);
        }
        
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
// Jesse and Cookies - hackerranck easy
int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> minHeap(A.begin(), A.end());
    
    int operations = 0;
    
    while (minHeap.size() > 1 && minHeap.top() < k) {
        int least = minHeap.top();
        minHeap.pop();
        
        int secondLeast = minHeap.top();
        minHeap.pop();
        
        int combined = least + 2 * secondLeast;
        minHeap.push(combined);
        
        operations++;
    }
    
    if (minHeap.top() < k) {
        return -1;
    }
    
    return operations;
}