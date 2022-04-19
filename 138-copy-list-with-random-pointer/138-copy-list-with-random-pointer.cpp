

class Solution {
public:
    //soln using constant extra space
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node *curr=head,*forw,*iter;
        //creating copy nodes
        while(curr){
            forw=curr->next;
            Node *cnode=new Node(curr->val);
            curr->next=cnode;
            cnode->next=forw;
            curr=forw;
        }
        curr=head;
        //assigning of rndm ptr of duplicated nodes
        while(curr){
           if(curr->random!=NULL){
               curr->next->random=curr->random->next;
           }
            curr=curr->next->next;
        }
        curr=head;
        Node *chead=curr->next;
        Node *temp=curr->next;
        
        while(curr){
            forw=temp->next;            
            temp->next=forw?forw->next:NULL;
            curr->next=forw;
            curr=forw;
            temp=temp->next;
        }
        return chead;
    }
};