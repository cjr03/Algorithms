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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        } else if (list2 == nullptr){
            return list1;
        } else {
            ListNode* head = new ListNode(0);
            ListNode* result = head;
            while(list1 != nullptr && list2 != nullptr){
                if(list1->val > list2->val){
                    result->next = new ListNode(list2->val);
                    result = result->next;
                    list2 = list2->next;
                } else if (list1->val < list2->val){
                    result->next = new ListNode(list1->val);
                    result = result->next;
                    list1 = list1->next;
                } else {
                    result->next = new ListNode(list1->val);
                    result = result->next;
                    list1 = list1->next;
                    result->next = new ListNode(list2->val);
                    result = result->next;
                    list2 = list2->next;
                }
            }
            while(list1 != nullptr){
                result->next = new ListNode(list1->val);
                result = result->next;
                list1 = list1->next;
            }
            while(list2 != nullptr){
                result->next = new ListNode(list2->val);
                result = result->next;
                list2 = list2->next;
            }
            return head->next;
        }
    }
};
