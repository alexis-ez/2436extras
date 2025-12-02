// BFS: Shortest Reach in a Graph - HackerRank Medium
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> dist(n + 1, -1);
    dist[s] = 0;
    
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 6;
                q.push(neighbor);
            }
        }
    }
    
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            result.push_back(dist[i]);
        }
    }
    
    return result;
}


// Clone Graph - Leetcode Medium
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> originalToClone;
        return dfs(node, originalToClone);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& originalToClone) {
        if (originalToClone.count(node)) {
            return originalToClone[node];
        }

        Node* clone = new Node(node->val);
        originalToClone[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, originalToClone));
        }

        return clone;
    }
};

// Number of Islands - Leetcode Medium
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
    
private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, 
                   vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);         
            backtrack(nums, i + 1, current, result);  
            current.pop_back();                   
        }
    }
};

// Network Delay Time - Leetcode Medium
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int weight = times[i][2];
            graph[u].push_back(make_pair(v, weight));
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, k));
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        while (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();
            
            int currentDist = current.first;
            int currentNode = current.second;
            
            if (currentDist > dist[currentNode]) {
                continue;
            }
            
            int numNeighbors = graph[currentNode].size();
            for (int i = 0; i < numNeighbors; i++) {
                int neighbor = graph[currentNode][i].first;
                int edgeWeight = graph[currentNode][i].second;
                int newDist = dist[currentNode] + edgeWeight;
                
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push(make_pair(newDist, neighbor));
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            if (dist[i] > maxTime) {
                maxTime = dist[i];
            }
        }
        
        return maxTime;
    }
};

// Climbing Stairs - Leetcode Easy
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        vector<int> dp(n + 1);
        dp[1] = 1;  
        dp[2] = 2;  
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};

// House Robber - Leetcode Medium
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
};
// Coin Change - Leetcode Medium
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  
        dp[0] = 0;  
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// Longest Increasing Subsequence - Leetcode Medium
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        
        for (int num : nums) {
            int left = 0, right = tails.size();
            
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tails[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            if (left == tails.size()) {
                tails.push_back(num);
            } else {
                tails[left] = num;
            }
        }
        
        return tails.size();
    }
};

// Longest Palindromic String - Leetcode Medium
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
