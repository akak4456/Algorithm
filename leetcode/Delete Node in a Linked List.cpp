/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* cur = node->next;
        if(cur->next == NULL){
            delete cur->next;
            node->next = NULL;
            return;
        }
        while(true){
            if(cur->next != NULL){
                cur->val = cur->next->val; 
                if(cur->next->next == NULL){
                    delete cur->next;
                    cur->next = NULL;
                    break;
                }else{
                    cur = cur->next;
                }
            }
        }
    }
};