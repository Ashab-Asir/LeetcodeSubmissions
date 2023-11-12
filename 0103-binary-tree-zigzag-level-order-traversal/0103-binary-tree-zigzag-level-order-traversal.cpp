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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int flag=0;
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>vec(size);
            for(int i=0;i<size;i++){
                TreeNode* x=q.front();
                q.pop();
                int index;
                if(flag==0){
                    index=i;
                }
                else{
                    index=size-1-i;
                }
                vec[index]=x->val;
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
        }
                flag=!flag;
                ans.push_back(vec);
        }
        return ans;
    }
};