class Solution {
public:
    // Check if a string is palindrome
    bool isPalindrome(const string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // Backtracking function
    void partitionHelper(string s, vector<string> &temp, vector<vector<string>> &ans) {
        if(s.empty()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1); // take prefix
            if(isPalindrome(part)) {
                temp.push_back(part);
                partitionHelper(s.substr(i + 1), temp, ans); // recur on remaining string
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partitionHelper(s, temp, ans);
        return ans;
    }
};
