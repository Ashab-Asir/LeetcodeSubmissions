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
    TreeNode* solve(int l,int r,vector<int>&vec){
        if(l>r){
            return NULL;
        }
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(vec[mid]);
        root->left=solve(l,mid-1,vec);
        root->right=solve(mid+1,r,vec);
        return root;
    }
    void inorder(TreeNode* root,vector<int>&vec){
        if(root==NULL){
            return ;
        }
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vec;
        inorder(root,vec);
        int n=vec.size();
        return solve(0,n-1,vec);
    }
};