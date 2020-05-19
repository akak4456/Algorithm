//result:Accepted
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(l1 != nullptr){
            cur->val = l1->val;
            if(l1->next == nullptr)
                break;
            l1 = l1->next;
            cur->next = new ListNode();
            cur = cur->next;  
        }
        cur = head;
        while(l2 != nullptr){
            //cout << cur->val << '\n';
            cur->val += l2->val;
            cout << cur->val << '\n';
            //cout << l2->val << ' '<<cur->val << '\n';
            ListNode* newCur = cur;
            while(newCur->val >= 10){
                cout << "OVER TEN\n";
                newCur->val -= 10;
                if(newCur->next == nullptr){
                    newCur->next = new ListNode(1);
                }else{
                    newCur->next->val++;
                }
                newCur = newCur->next;
            }
            if(l2->next == nullptr){
                break;
            }
            l2 = l2->next;
            if(cur->next == nullptr){
                cur->next = new ListNode();
            }
            cur = cur->next;  
        }
        return head;
    }
};