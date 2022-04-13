
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forw;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=forw;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr)return true;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
      
        ListNode* nhead=reverseList(slow->next);
        slow->next=nullptr;
        slow=head;
        
        while(slow and nhead){
            if(slow->val!=nhead->val)return false;
            slow=slow->next;
            nhead=nhead->next;
        }
        
        return true
            ;
        
    }
};