/*
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0){
            return head;
        } else if(!head){
            return nullptr;
        } else {
            ListNode* curr = head;
            int length = 1;
            while(curr->next){
                curr = curr->next;
                ++length;
            }
            curr->next = head;
            k %= length;
            int stepsToNewHead = length - k;
            for(int i = 0; i < stepsToNewHead; ++i){
                curr = curr->next;
            }
            ListNode* newStart = curr->next;
            curr->next = nullptr;
            return newStart;
        }
    }
};
