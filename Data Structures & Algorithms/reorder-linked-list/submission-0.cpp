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
    void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;


    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = slow->next;
    slow->next =NULL;

    ListNode* rev = NULL;

    while(second!=NULL){
        ListNode* nextNode = second->next;
        second->next = rev;
        rev = second;
        second = nextNode;
    }

    ListNode* first = head;

    while(rev!=NULL){
        ListNode* nextNode = first->next;
        ListNode* nextNode1 = rev->next;
        first->next = rev;
        rev->next = nextNode;
        
        rev = nextNode1;
        first = nextNode;
    }

}};