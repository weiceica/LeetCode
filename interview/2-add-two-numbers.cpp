
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

#include <list>
using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {    
        // basecase
        if(l1->next == nullptr && l2->next == nullptr && l1->val + l2->val < 10){
            return new ListNode(l1->val + l2->val);
        }
        else if(l1->next == nullptr && l2->next == nullptr && l1->val + l2->val >= 10){
            ListNode* n = new ListNode((l1->val + l2->val) % 10);
            n->next = new ListNode(1);
            return n;
        }

        ListNode* l1Pointer = l1;
        ListNode* l2Pointer = l2;
        int carry = 0;
        if(l1Pointer->val + l2Pointer->val >= 10) carry = 1;
        ListNode* result = new ListNode((l1Pointer->val + l2Pointer->val) % 10);
        ListNode* headNode = result;
        l1Pointer = l1Pointer->next;
        l2Pointer = l2Pointer->next;
        result->next = new ListNode();
        result = result->next;

        while(l1Pointer != nullptr || l2Pointer != nullptr){
            int sum;
            if(l1Pointer == nullptr){
                sum = l2Pointer->val + carry;
                l2Pointer = l2Pointer->next;
            }else if(l2Pointer == nullptr){
                sum = l1Pointer->val + carry;
                l1Pointer = l1Pointer->next;
            }
            else{
                sum = l2Pointer->val + l1Pointer->val + carry;
                l1Pointer = l1Pointer->next;
                l2Pointer = l2Pointer->next;
            }
            if(sum >= 10) carry = 1;
            else carry = 0;
            result->val = sum % 10;
            if(l1Pointer == nullptr && l2Pointer == nullptr){
                if(carry == 0) break;
                else{
                    result->next = new ListNode();
                    result = result->next;
                    result->val = 1;
                    break;
                }
            }
            result->next = new ListNode();
            result = result->next;
        }
        return headNode;
    }
};