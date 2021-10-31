/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head==NULL)
            return NULL;
        
        
        Node* ptr=head;
        if(!head->child)
        {
            Node* ptrr=flatten(head->next);
            head->next=ptrr;
            if(ptrr!=NULL)
                ptrr->prev=head;
                
            
            return head;
        }
        
        Node* ptr2=ptr->next;
        Node* ptr3=flatten(ptr->child);
        ptr->child=NULL;
        ptr->next=ptr3;
         if(ptr3!=NULL)
                ptr3->prev=ptr;
        
        while(ptr3->next!=NULL)
            ptr3=ptr3->next;
        
        ptr3->next=ptr2;
        
         if(ptr2!=NULL)
                ptr2->prev=ptr3;
     
        
        return head;
        
    }
};
