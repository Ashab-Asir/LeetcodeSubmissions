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
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        int ans=0,i=0,cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        cnt=cnt-1;
        temp=head;
        while(temp!=NULL){
            ans=ans+(temp->val)*pow(2,cnt);
            temp=temp->next;
            cnt--;
        }
        return ans;
    }
};