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
    struct comp{
        bool operator()(const ListNode *l,const ListNode* r){
            return l->val>r->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        
        for(auto l:lists){
            if(l)pq.push(l);
        }
        if(pq.empty())return NULL;
        ListNode* res=pq.top();
        pq.pop();
        if(res->next)pq.push(res->next);
        ListNode *t=res;
        while(pq.size()!=0){
            t->next=pq.top();
            pq.pop();
            t=t->next;
            if(t->next)pq.push(t->next);
        }
        
        return res;
    }
};