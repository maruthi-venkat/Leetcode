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
    vector<int> res;
    void levelorder(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<n;i++){
                auto curr = q.front();
                maxi = max(maxi,curr->val);
                if(curr -> left)
                    q.push(curr->left);
                if(curr -> right)
                    q.push(curr->right);
                q.pop();
            }
            res.push_back(maxi);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return{};
        levelorder(root);
        return res;
    }
};