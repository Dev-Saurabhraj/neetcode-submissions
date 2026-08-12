/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        unordered_map<Node*, Node*> mp;

        Node* oldHead = head;

        Node* newlist = &dummy;
        Node* temp = newlist;
        while(head!=NULL){
            Node* newNode = new Node(head->val);
            mp[head] = newNode;
            temp->next = newNode;
            temp = temp->next;
            head = head->next;
        }
        Node* list = newlist->next;

        while(list!=NULL){

            Node *copiedNode = mp[oldHead->random];

            list->random = copiedNode;
            list = list->next;
            oldHead = oldHead->next;
        }
        
        return newlist->next;
    }
};
