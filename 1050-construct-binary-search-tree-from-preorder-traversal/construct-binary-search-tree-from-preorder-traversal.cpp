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

    void insertNode(TreeNode* &root,int x){
        TreeNode* temp=root;
        TreeNode* prev=root;
        while(temp){
            if(temp -> val < x){
                prev = temp;
                temp = temp -> right;
            }
            else{
                prev = temp;
                temp = temp -> left;
            }
        }

        if(prev && prev -> val < x){
            TreeNode* newnode = new TreeNode(x);
            prev -> right = newnode;
        }
        else if(prev && prev -> val > x){
            TreeNode* newnode = new TreeNode(x);
            prev -> left = newnode;
        }

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insertNode(root,preorder[i]);
        }

        return root;
    }
};