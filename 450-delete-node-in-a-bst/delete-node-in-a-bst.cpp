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
    void search(TreeNode* &root,int key){
        TreeNode* temp = root;
        TreeNode* prev = nullptr;
        int dir = -1;
        while(temp){
            if(temp -> val == key){
                if(!temp -> right && !temp -> left){
                    if(dir == 0){
                        prev -> left = nullptr;
                    }
                    else if(dir == 1){
                        prev -> right = nullptr;
                    }
                    else{
                        root = nullptr;
                    }
                    return;
                }
                else if(!temp -> right){
                    if(dir == 0){
                        prev -> left = temp -> left;
                    }
                    else if(dir == 1){
                        prev -> right = temp -> left;
                    }
                    else{
                        root = temp -> left;
                    }
                    return;
                }
                else if(!temp -> left){
                    if(dir == 0){
                        prev -> left = temp -> right;
                    }
                    else if(dir == 1){
                        prev -> right = temp -> right;
                    }
                    else{
                        root = temp -> right;
                    }
                    return;
                }
                else{
                    TreeNode* rpart = temp -> right;
                    TreeNode* lpart = temp -> left;
                    temp -> right = nullptr;
                    if(dir == 0){
                        prev -> left = lpart;
                    }
                    else if(dir == 1){
                        prev -> right = lpart;
                    }
                    else{
                        root = lpart;
                    }
                    
                    TreeNode* rightmost = lpart;
                    while(rightmost -> right) {
                        rightmost = rightmost -> right;
                    }
                    rightmost -> right = rpart;
                    return;
                }
            }
            else if(key < temp -> val){
                prev = temp;
                dir = 0;
                temp = temp -> left;
            }
            else{
                prev = temp;
                dir = 1;
                temp = temp -> right;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        search(root,key);

        return root;
    }
};