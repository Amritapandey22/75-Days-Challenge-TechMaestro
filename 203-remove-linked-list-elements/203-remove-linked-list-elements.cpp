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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        while(head and head->val==val)head=head->next;
        if(head==nullptr)return head;
        ListNode *curr=head;
        while(curr and curr->next){
            if(curr->next->val==val){
                cout<<curr->val<<endl;
                curr->next=curr->next->next;
            }else curr=curr->next;
        }
      //1 2 6
         return head;
    }
};