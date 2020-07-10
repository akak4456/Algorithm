/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head){
        Node* cur = head;
        while(cur != NULL){
            cout << head->val << ' ' << cur->val << endl;
            Node* oldCurNext = cur->next;
            if(cur->child != NULL){
                Node* newHead = solve(cur->child);
                Node* newTail = newHead;
                while(newTail->next != NULL){
                    newTail = newTail->next;
                }
                cur->next = newHead;
                newHead->prev = cur;
                newTail->next = oldCurNext;
                if(oldCurNext != NULL)
                    oldCurNext->prev = newTail;
                cur->child = NULL;
            }
            cur = oldCurNext;
        }
        return head;
    }
    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;
        return solve(head);
    }
};