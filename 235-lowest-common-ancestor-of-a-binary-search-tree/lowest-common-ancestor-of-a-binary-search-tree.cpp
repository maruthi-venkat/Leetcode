/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* parent){
        if(!root) return;
        mp[root] = parent;
        preorder(root -> left,mp,root);
        preorder(root -> right,mp,root);
    }

    void dis_to_root(TreeNode* root,TreeNode* x,int &l){
        if(root == x) return;
        l++;
        if(x -> val < root -> val){
            dis_to_root(root -> left,x,l);
        }
        else{
            dis_to_root(root -> right,x,l);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*> mp;
        preorder(root,mp,nullptr);

        int l1=0,l2=0;
        dis_to_root(root,p,l1);
        dis_to_root(root,q,l2);

        if(l1 < l2){
            int up = l2-l1;
            while(up--){
                q = mp[q];
            }
        }
        else{
            int up = l1-l2;
            while(up--){
                p = mp[p];
            }
        }
        while(p != q){
            p=mp[p];
            q=mp[q];
        }
        
        return p;
    }
};