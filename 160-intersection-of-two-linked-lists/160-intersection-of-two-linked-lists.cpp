/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //difference method,
    //calculate length and start them from same point like l1=5 and l2=3 move l1 to 2 ptr ahead and start
    //they will meet at intersection node for sure
    
    int getLen(ListNode *head){
        int len=1;
        
        while(head){
            head=head->next;
            len+=1;
        }
        
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int len1= getLen(headA);
       int len2= getLen(headB); 
        
        while(len1>len2){
            headA=headA->next;len1--;
        }
        while(len2>len1){
            headB=headB->next;len2--;
        }
        
        ListNode *ptrA=headA;
        ListNode *ptrB=headB;
        
        while(ptrA and ptrB){
            if(ptrA==ptrB)return ptrA;
            ptrA=ptrA->next;
            ptrB=ptrB->next;
            
            
                
        }
        
        return nullptr;
    }
};