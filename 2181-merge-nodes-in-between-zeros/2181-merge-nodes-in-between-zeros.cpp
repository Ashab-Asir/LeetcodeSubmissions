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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        int sum = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* root = dummy;
        int flag = 0;
        while (head != NULL) {
            if (head->val != 0) {
                sum += head->val;
            } else {
                ListNode* newNode = new ListNode(sum);
                root->next = newNode;
                root=root->next;
                sum = 0;
            }
            head = head->next;
        }
        return dummy->next;
    }
};