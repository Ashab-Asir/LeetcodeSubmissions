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
    ListNode* doubleIt(ListNode* head) {
        stack<int>st;
        while(head!=NULL){
            st.push(head->val);
            head=head->next;
        }
        int carry=0;
        stack<int>st2;
        while(!st.empty()){
            int x=st.top()*2+carry;
            st2.push(x%10);
            carry=x/10;
            st.pop();
        }
        if(carry>0){
            st2.push(carry);
        }
        ListNode* first=new ListNode(st2.top());
        ListNode* ansRoot=first;
        st2.pop();
        while(!st2.empty()){
            ListNode* node=new ListNode(st2.top());
            first->next=node;
            first=first->next;
            st2.pop();
        }
        return ansRoot;
    }
};