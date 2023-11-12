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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameater=0;
        height(root,diameater);
        return diameater;
    }
private:
    int height(TreeNode* root,int &diameater){
        if(root==NULL){
            return 0;
        }
        int leftHeight=height(root->left,diameater);
        int rightHeight=height(root->right,diameater);
        diameater=max(diameater,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
};