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
    ListNode* merge2(ListNode* l1,ListNode* l2){
        if(l1==nullptr or l2==nullptr)return l1==nullptr?l2:l1;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(l1 and l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
                
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            
            temp=temp->next;
        }
        
        if(l1)temp->next=l1;
        if(l2)temp->next=l2;
        
        return dummy->next;
    }
     ListNode* mergeKLists(vector<ListNode*>& lists,int si,int ei){
         if(si==ei)return lists[si];
         int mid=si+(ei-si)/2;
         
         ListNode* lh=mergeKLists(lists,si,mid);
         ListNode* rh=mergeKLists(lists,mid+1,ei);
         
         return merge2(lh,rh);
     }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        int n=lists.size();
        return mergeKLists(lists,0,n-1);
        
    }
};