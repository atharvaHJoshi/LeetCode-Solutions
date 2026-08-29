class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<vector<pair<int, int>>> groups;
        groups.push_back({sorted_nums[0]});
        
        for (int i = 1; i < n; ++i) {
            if (sorted_nums[i].first - sorted_nums[i - 1].first <= limit) {
                groups.back().push_back(sorted_nums[i]);
            } else {
                groups.push_back({sorted_nums[i]});
            }
        }
        
        vector<int> result(n);
        for (const auto& group : groups) {
            vector<int> indices;
            for (const auto& p : group) {
                indices.push_back(p.second);
            }
            sort(indices.begin(), indices.end());
            
            for (size_t i = 0; i < indices.size(); ++i) {
                result[indices[i]] = group[i].first;
            }
        }
        
        return result;
    }
};
