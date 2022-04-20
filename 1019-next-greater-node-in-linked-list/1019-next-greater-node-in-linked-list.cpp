
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* p=head;
        ListNode* q=head;
        while(p){
            q=p->next;
            int val=0;
            while(q){
               if(q->val>p->val){
                   val=q->val;
                   q=nullptr;
               }
               else q=q->next;
            }
            ans.push_back(val);
            p=p->next;
        }
        
        return ans;
    }
};