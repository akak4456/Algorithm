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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            if(prev != nullptr){
                cout << "prev:"<<prev->val << ' ';
            }
            cout << cur->val << endl;
            if(cur->val == val){
                ListNode* deletedNode = cur;
                if(prev != nullptr){
                    prev->next = cur->next;
                    cur = prev->next;
                }else{
                    cout << "AAA\n";
                    head = cur->next;
                    cur = cur->next;
                    if(head == nullptr)
                        return nullptr;
                }
                delete deletedNode;
            }else{
                if(prev == nullptr){
                    prev = cur;
                }else{
                    prev = prev->next;
                }
                cur = cur->next;
            }
        }
        return head;
    }
};