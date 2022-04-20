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
    ListNode* oddEvenList(ListNode* head) {
      if(!head or !head->next)return head;
        ListNode* evptr=head->next,*odptr=head,*evhead=head->next;
        while(evptr and evptr->next){
            odptr->next=odptr->next->next;
            evptr->next=evptr->next->next;
            
            evptr=evptr->next;
            odptr=odptr->next;
        }
        
        odptr->next=evhead;
        
        return head;
    }
};