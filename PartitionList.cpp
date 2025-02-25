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
    ListNode* partition(ListNode* head, int x) {
        ListNode* gtX = new ListNode(0), *gtHead = gtX;
        ListNode* ltX = new ListNode(0), *ltHead = ltX;
        ListNode* current = head;

        while(current != nullptr){
            if(current->val < x){
                ltX->next = current;
                ltX = ltX->next;
            } else {
                gtX->next = current;
                gtX = gtX->next;
            }
            ListNode* nextNode = current->next;
            current->next = nullptr;
            current = nextNode;
        }
        ltX->next = gtHead->next;

        ListNode* result = ltHead->next;
        delete gtHead, ltHead;    
        return result;
    }
};
