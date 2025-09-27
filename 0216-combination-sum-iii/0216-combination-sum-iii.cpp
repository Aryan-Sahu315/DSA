class Solution {
public:
    void combine(int k, int start, int n, vector<vector<int>> &ans, vector<int> &temp) {
        if(temp.size() == k && n == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = start; i <= 9; i++) {
            if(i > n) break; // pruning, no need to continue
            temp.push_back(i);
            combine(k, i + 1, n - i, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        combine(k, 1, n, ans, temp); // start from 1
        return ans;
    }
};
