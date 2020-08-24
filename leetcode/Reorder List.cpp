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
        if(head == nullptr || head->next == nullptr)
            return;
        ListNode* start;
        ListNode* startNext;
        ListNode* lastPrev;
        ListNode* last;
        start = head;
        startNext = start->next;
        while(start->next->next != nullptr){
            ListNode* cur = head;
            lastPrev = start;
            while(true){
                if(lastPrev->next->next == nullptr){
                    last = lastPrev->next;
                    break;
                }
                lastPrev = lastPrev->next;
            }
            start->next = last;
            last->next = startNext;
            lastPrev->next = nullptr;
            start = startNext;
            if(start->next == nullptr)
                break;
            startNext = start->next;
        }
    }
};