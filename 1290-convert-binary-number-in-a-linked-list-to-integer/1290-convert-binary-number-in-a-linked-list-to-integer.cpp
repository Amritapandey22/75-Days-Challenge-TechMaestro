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
    ListNode *reverseList(ListNode *head){
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
    int getDecimalValue(ListNode* head) {
        head=reverseList(head);
        int pow=1;
        int ans=0;
        while(head){
            ans+=head->val*pow;
            pow*=2;
            head=head->next;
        }
        return ans;
    }
};