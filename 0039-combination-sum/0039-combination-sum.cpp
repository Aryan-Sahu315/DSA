class Solution {
public:
    void backtrack(vector<int>& candidates, int start, int target,
                   vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; // skip if too large

            // Choose the number
            temp.push_back(candidates[i]);

            // Call again with i (not i+1) because we can reuse same element
            backtrack(candidates, i, target - candidates[i], temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(candidates, 0, target, temp, ans);
        return ans;
    }
};
