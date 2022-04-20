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
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head or !head->next)return head;
        ListNode* curr=head->next;
        ListNode* dummy=new ListNode(-1);
        ListNode* itr=dummy;
        itr->next=head;
        bool check=false;
        while(curr){
            check=false;
            while(curr and itr->next->val==curr->val){
                check=true;
                curr=curr->next;
            }
            
            if(check)itr->next=curr;
            else itr=itr->next;
            
            if(curr)curr=curr->next;
        }
        
        return dummy->next;
    }
};