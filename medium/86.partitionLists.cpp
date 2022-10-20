//
// Created by weice on 10/20/2022.
//
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* firstPartition = new ListNode(-1);
        ListNode* secondPartition = new ListNode(-1);
        ListNode* firstTail = firstPartition;
        ListNode* secondTail = secondPartition;
        ListNode* current = head;

        while(current != nullptr){
            ListNode* temp = current;
            current = current->next;
            temp->next = nullptr;
            if(temp->val < x){
                firstTail->next = temp;
                firstTail = firstTail->next;
            }
            else{
                secondTail->next = temp;
                secondTail = secondTail->next;
            }
            firstTail->next = secondPartition->next;
        }
        return firstPartition->next;
    }
};
