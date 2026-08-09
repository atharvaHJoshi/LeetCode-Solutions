class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        int target = n / 3; 

        for (int i = 0; i < n; i++) {
            // Check whether if we have already added this number to our results or not
            if (find(ls.begin(), ls.end(), nums[i]) != ls.end()) {
                continue; 
            }

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }
            if (count > target) {
                ls.push_back(nums[i]);
            }
        }
        return ls;
    }
};
