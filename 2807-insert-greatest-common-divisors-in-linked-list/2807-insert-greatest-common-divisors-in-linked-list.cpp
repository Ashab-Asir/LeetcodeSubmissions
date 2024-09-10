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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        ListNode* nextNode=curr->next;
        if(head==NULL || nextNode==NULL){
            return head;
        }
        while(nextNode!=NULL){
            ListNode* newNode=new ListNode(__gcd(curr->val,nextNode->val));
            curr->next=newNode;
            newNode->next=nextNode;
            curr=nextNode;
            nextNode=curr->next;
        }
        return head;
        
    }
};