// 128. Longest Consecutive Sequence - leetcode medium
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        
        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLen = 1;
                
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLen++;
                }
                
                maxLen = max(maxLen, currentLen);
            }
        }
        
        return maxLen;
    }
};
// 560. Subarray sum equals k - leetcode medium
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        
        int cumSum = 0;
        int count = 0;
        
        for (int num : nums) {
            cumSum += num;
            
            if (prefixCount.find(cumSum - k) != prefixCount.end()) {
                count += prefixCount[cumSum - k];
            }
            
            prefixCount[cumSum]++;
        }
        
        return count;
    }
};
