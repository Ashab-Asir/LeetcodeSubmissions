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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int len=0;
        ListNode* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        int eachBucketNode=len/k;
        int remainNodes=len%k;
        curr=head;
        ListNode* prev=NULL;
        vector<ListNode*>ans(k,NULL);
        for(int i=0;i<k;i++){
            ans[i]=curr;
            for(int cnt=1;cnt<=eachBucketNode+(remainNodes>0?1:0);cnt++){
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
                prev->next=NULL;
            }
            remainNodes--;
        }
        return ans;
    }
};