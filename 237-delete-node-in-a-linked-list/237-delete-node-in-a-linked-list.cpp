
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *forw=node->next;
        while(forw->next){
            node->val=forw->val;
            //cout<< node->val<<endl;
            node=node->next;
            forw=forw->next;
        }
        node->val=forw->val;
        
        //forw->val=forw->next->val;
        node->next=nullptr;
    }
};