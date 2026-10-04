#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Special base case for a single node
        if (n == 1) {
            return {0};
        }
        
        // 1. Build adjacency list and compute degrees
        vector<vector<int>> g(n);
        vector<int> degree(n, 0);
        
        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        
        // 2. Add all initial leaf nodes (degree == 1) to the queue
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        // 3. Trim leaf nodes layer by layer until 2 or fewer nodes remain
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size; // Reduce count by current layer size
            
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                
                // Reduce degree of neighbors
                for (int neighbor : g[curr]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        // 4. The remaining nodes in the queue are the central roots
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};
