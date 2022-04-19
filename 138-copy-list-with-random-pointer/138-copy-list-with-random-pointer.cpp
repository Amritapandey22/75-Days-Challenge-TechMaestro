/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        unordered_map<Node*,Node*>mp;
        Node *curr=head;
        Node *chead=new Node(curr->val);
        Node *temp=chead;
        
        while(curr){
            curr=curr->next;
            temp->next=curr ? new Node(curr->val):NULL;
            temp=temp->next;
        }
        curr=head;
        temp=chead;
        while(curr){
            mp[curr]=temp;
            curr=curr->next;
            temp=temp->next;
        }
        curr=head;
        temp=chead;
        while(curr){
            Node *t=curr->random;
            Node *p=t?mp[t]:NULL;
            temp->random=p;
            curr=curr->next;
            temp=temp->next;            
        }
        return chead;
    }
};