class Solution {
public:
    void subsets(vector<int> &nums, int index, int n, vector<vector<int>> &ans, vector<int> &temp) {
        ans.push_back(temp);  // add current subset
        
        for(int i = index; i < n; i++) {
            if(i > index && nums[i] == nums[i-1]) continue; // skip duplicates
            temp.push_back(nums[i]);
            subsets(nums, i+1, n, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important for duplicate handling
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        subsets(nums, 0, n, ans, temp);
        return ans;
    }
};
