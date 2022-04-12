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
    int pairSum(ListNode* head) {
        
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *prev=nullptr,*curr=slow,*forward;
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
       // cout<<slow->val;
        //prev is new head 
        slow=head;
        int sum=0;
        while(slow->next){
          sum=max(sum,slow->val+prev->val);  
           //cout<<slow->val<<prev->val<<endl;
          slow=slow->next;
          prev=prev->next;
        }
        return sum;
    }
};