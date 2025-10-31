/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if (root == NULL) return answer;
        
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size(); 
            TreeNode *temp = NULL;

            for (int i = 0; i < size; i++) {
                temp = que.front();
                que.pop();

                
                if (temp->left != NULL) que.push(temp->left);
                if (temp->right != NULL) que.push(temp->right);
            }

            
            answer.push_back(temp->val);
        }

        return answer;
    }
};
