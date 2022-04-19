

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr)return head;
       Node* h=head,*n;
        while(h){
            if(h->child){
                n=h->next;
                h->next=h->child;
                h->next->prev=h;
                h->child=nullptr;
                Node* p=h->next;
                while(p->next){
                    p=p->next;
                }
                p->next=n;
                if(n)n->prev=p;
            }
            h=h->next;
        }
        return head;
    }
};