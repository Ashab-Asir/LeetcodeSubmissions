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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unorder_set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        While(st.find(head->val)!=st.end()){
            head=head->next;
        }
        ListNode* curr=head;
        while(curr->next){
            if(st.find(curr->next)!=st.end()){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return curr;
    }
};