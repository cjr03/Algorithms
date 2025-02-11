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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return nullptr;
        } else {
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode* curr = dummy->next, *prev = dummy;
            int length = 0, count = 0;
            while(curr){
                curr = curr->next;
                ++length;
            }
            curr = dummy->next;
            while(curr){
                if(count == length - n){
                    prev->next = curr->next;
                    break;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
                ++count;
            }
            return dummy->next;
        }
    }
};
