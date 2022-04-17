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
    ListNode* tempHead=nullptr;
    ListNode* tempTail=nullptr;
    
    void addFirst(ListNode* node){
        if(tempHead==nullptr and tempTail==nullptr){
            tempHead=node;
            tempTail=node;
        }else{
            node->next=tempHead;
            tempHead=node;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
      int len=0;
        ListNode* curr=head;
        ListNode* ghead=nullptr;
        ListNode* gtail=nullptr;
        
        while(curr){
            curr=curr->next;
            len++;
        }
        
        curr=head;
        
        while(curr and len-k>=0){
            
           int tempK=k;
            while( tempK--){
                ListNode* forw=curr->next;
                curr->next=nullptr;
                addFirst(curr);
                curr=forw;
            }
            
            if(ghead==nullptr and gtail==nullptr){
                ghead=tempHead;
                gtail=tempTail;
            }else{
                gtail->next=tempHead;
                gtail=tempTail;
            }
            
            tempHead=tempTail=nullptr;
            len-=k;
        }
        gtail->next=curr;
        return ghead;
    }
};