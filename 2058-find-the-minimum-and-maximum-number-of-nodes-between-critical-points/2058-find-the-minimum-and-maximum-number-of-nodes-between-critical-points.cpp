/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        vector<int>vec;
        int currPosition=1;
        while(curr!=NULL){
            if(prev!=NULL && curr->next!=NULL && 
            (prev->val>curr->val&& curr->next->val>curr->val)
            ){
                vec.push_back(currPosition);
            }
            else if(prev!=NULL && curr->next!=NULL && 
            (prev->val<curr->val&& curr->next->val<curr->val)){
                vec.push_back(currPosition);
            }
            prev=curr;
            curr=curr->next;
            currPosition++;
        }
        if(vec.size()<=1){
            return {-1,-1};
        }
        int maxi=abs(vec[0]-vec[vec.size()-1]);
        cout<<maxi;
        int mini=INT_MAX;
        for(int i=0;i<vec.size();i++){
            if(i+1<vec.size() && vec[i+1]-vec[i]<mini){
                mini=vec[i+1]-vec[i];
            }
        }
        
        return {mini,maxi};
    }
};