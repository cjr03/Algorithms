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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head; 
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy; 
        ListNode* curr = head;

        while (curr) {
            ListNode* groupStart = curr;
            ListNode* groupEnd = curr;
            int count = 1;

            while (groupEnd && count < k) {
                groupEnd = groupEnd->next;
                count++;
            }

            if (!groupEnd) {
                break; 
            }

            ListNode* nextGroupStart = groupEnd->next;

            ListNode* prev = nullptr;
            ListNode* temp = groupStart;
            while (temp != nextGroupStart) {
                ListNode* nextNode = temp->next;
                temp->next = prev;
                prev = temp;
                temp = nextNode;
            }

            prevGroupEnd->next = groupEnd;
            groupStart->next = nextGroupStart; 
            prevGroupEnd = groupStart;
            curr = nextGroupStart;
        }

        return dummy->next;
    }
};
