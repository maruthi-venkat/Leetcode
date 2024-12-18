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
    bool res = true;
    void helper(TreeNode* root,pair<long,long> p){
        if(!root) return;
        if(root -> val > p.first && root -> val < p.second){
            helper(root -> left,{p.first,root -> val});
            helper(root -> right,{root -> val,p.second});
        }
        else{
            res = false;
        }
    }
    bool isValidBST(TreeNode* root) {
        helper(root,{LONG_MIN,LONG_MAX});
        return res;
    }
};