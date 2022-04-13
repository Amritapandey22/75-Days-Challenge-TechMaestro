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
    ListNode* reverseList(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=nullptr;
        ListNode *forw;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=forw;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        l1=reverseList(l1);
        l2=reverseList(l2);
        
       
        
        int carry=0;
        ListNode* dummy=new ListNode(-1);
              ListNode* temp=dummy;
        while(l1 or l2 or carry){
            int sum=carry;
            if(l1)sum+=l1->val;
            if(l2)sum+=l2->val;
             
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            carry=sum/10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        
        return reverseList(dummy->next);    
        
        
        
    }
};