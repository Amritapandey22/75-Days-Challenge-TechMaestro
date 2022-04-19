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
        
        ListNode* p=head;
        ListNode* q=head->next;
        
        while(q->next){
            if(p->val!=q->val){
                p->next=q;
                p=p->next;
            }else p->next=nullptr;
            q=q->next;
        }
        if(p->val!=q->val)p->next=q;
        else p->next=NULL;
        
        return head;
    }
};