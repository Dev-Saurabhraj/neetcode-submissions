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
        ListNode* temp = head;
        int len = 0;
        if(head->next ==NULL || head==NULL) return NULL;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }

        int pos = len - n;


        if(pos == 0){
            ListNode* nextNode = head->next;
            delete head;
            return nextNode;
        }
        ListNode* list = head;

        for(int i = 0; i<pos-1; i++){
            list = list->next;
        }

        ListNode* nextNode = list->next;
        list->next = nextNode->next;

        delete(nextNode);

        return head;
    }
};