// 238. Product of Array Except Self -leetcode medium
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};
// 2. Two Sum - leetcode easy
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); i++){
            int complement = target - nums[i];
            for (int j = i + 1; j<nums.size(); j++){
                if (nums[j] == complement){
                    return {i, j};
                }
            }
        
        }
        return {};
    }
};

