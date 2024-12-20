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
    void inorder(TreeNode* root,vector<int> &arr){
        if(!root) return;
        inorder(root -> left,arr);
        arr.push_back(root -> val);
        inorder(root -> right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        for(int i=0;i<arr.size();i++){
            int x = k - arr[i];
            for(int l=i+1,r=arr.size()-1;l<=r;){
                int mid = (l+r)/2;
                if(arr[mid] == x){
                    return true;
                }
                else if(arr[mid] < x){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};