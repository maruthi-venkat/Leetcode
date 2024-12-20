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
class BSTIterator {
public:
    vector<int> arr;
    int index = 0;

    void helper(TreeNode* root){
        if(!root) return;
        helper(root -> left);
        arr.push_back(root -> val);
        helper(root -> right);
    }

    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
        int x= arr[index];
        index++;
        return x;
    }
    
    bool hasNext() {
        if(index < arr.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */