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
    void makeGraph(TreeNode* root,TreeNode* prev, 
    unordered_map<TreeNode*,vector<TreeNode*>>&adj,
    unordered_set<TreeNode*>&st){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            st.insert(root);
        }
        if(prev!=NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makeGraph(root->left,root,adj,st);
        makeGraph(root->right,root,adj,st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>st;
        makeGraph(root,NULL,adj,st);
        int cnt=0;
        for(auto &it:st){
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visited;
            q.push(it);
            visited.insert(it);
            for(int level=0;level<=distance;level++){
                int size=q.size();
                while(size--){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr!=it && st.count(curr)){
                        cnt++;
                    }
                    for(auto &ngbr:adj[curr]){
                        if(!visited.count(ngbr)){
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return cnt/2;
    }
};