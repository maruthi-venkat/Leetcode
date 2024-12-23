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
    int count = 0;

    void helper(vector<int> arr,vector<int> actual){
        sort(actual.begin(),actual.end());
        // cout<<actual[0]<<actual[actual.size()-1]<<endl;
        for(int i=0;i<arr.size();i++){
            if(arr[i] != actual[i]){
                for(int j=i+1;j<arr.size();j++){
                    if(arr[j] == actual[i]){
                        swap(arr[i],arr[j]);
                        count++;
                        break;
                    }
                }
            }
        }
    }

    void levelorder(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> arr;
            for(int i=0;i<n;i++){
                auto curr = q.front();
                arr.push_back(curr -> val);
                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);

                q.pop();
            }
            helper(arr,arr);
           
        }
    }

    int minimumOperations(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        levelorder(root);
        return count;
    }
};