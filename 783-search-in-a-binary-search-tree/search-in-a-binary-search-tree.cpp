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
    TreeNode* searchBST(TreeNode* root, int x) {
        if(!root){
            return nullptr;
        }

        if(root -> val == x){
            return root;
        }

        if(root -> left && x < root -> val ){
            return searchBST(root -> left, x);
        }
        else if(root -> right && x > root -> val){
            return searchBST(root -> right, x);
        }

        return nullptr;
    }
};