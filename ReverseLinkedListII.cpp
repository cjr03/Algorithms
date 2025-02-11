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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right){
            return head;
        }
        ListNode* output = new ListNode(0);
        output->next = head;
        ListNode *leftNode = output;
        for(int i = 1; i < left; ++i){
            leftNode = leftNode->next;
        }
        ListNode* prev = nullptr, *curr = leftNode->next, *next = nullptr;
        for(int i = left; i <= right; ++i){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        leftNode->next->next = curr;
        leftNode->next = prev;
        return output->next;        
    }
};
