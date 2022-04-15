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
    int getLen(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        
        return len;
    }
    
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
    ListNode* getTail(ListNode* head){
        while(head->next){
            head=head->next;
        }
        
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr or head->next==nullptr)return head;
        int len=getLen(head);k=k%len;
        ListNode* cur=head;
        for(int i=0;i<len-k-1;i++){
            cur=cur->next;
        }
        
        ListNode* forw=cur->next;
        //cout<<cur->val<<" "<<forw->val;
        cur->next=nullptr;
        
        ListNode* fHalfHead=reverseList(head);
        ListNode* sHalfHead=reverseList(forw);
        
        ListNode* fHalfTail=getTail(fHalfHead);
        fHalfTail->next=sHalfHead;
        
        return reverseList(fHalfHead);
    }
};