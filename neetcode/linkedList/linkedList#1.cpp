#include <list>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* previous = head;
        while(current != nullptr){
            ListNode* c = current->next;
            if(current == head){
                current->next = nullptr;
            }
            else{
                current->next = previous;
            }
            previous = current;
            current = c;
        }
        return previous;
    }
};