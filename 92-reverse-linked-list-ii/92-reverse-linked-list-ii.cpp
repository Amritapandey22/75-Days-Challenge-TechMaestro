
class Solution {
public:
     ListNode *reverseList(ListNode* head){
        if(head == nullptr or head->next == nullptr)return head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextptr;
        while(curr != nullptr){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode *itr = head;
        if(left == 1)temp->next = head;
        else{
           for(int i=1;i<left-1;i++) itr = itr->next;        
           temp->next = itr->next; 
            itr->next = nullptr;
        }
        for(int i=left;i<= right;i++){
            temp = temp->next;
            
        }//cout<<temp->val;
        ListNode *atail = temp->next;
        temp->next = nullptr;
        ListNode *newAhead = reverseList(dummy->next);
        //cout<<newAhead->val;
        ListNode *revTail = newAhead;
        while(revTail->next != nullptr)revTail=revTail->next;
        
        revTail->next = atail;
        //cout<<revTail->next->val;
        if(left != 1 ){
            itr->next = newAhead;
            return head;
        }
        return newAhead;
        
        
        
        
        
    }
};