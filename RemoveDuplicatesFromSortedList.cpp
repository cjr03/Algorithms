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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return nullptr;
        } else {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* preprev = dummy, *prev = preprev->next, *curr = prev->next;
            while(curr){
                if(prev->val == curr->val){
                    while (curr && prev->val == curr->val) {
                        curr = curr->next;
                    }
                    preprev->next = curr;
                    prev = curr;
                    if(curr){
                        curr = curr->next;
                    }
                } else {
                    preprev = prev;
                    prev = curr;
                    curr = curr->next;
                }
            }
            return dummy->next;
        }
    }
};
