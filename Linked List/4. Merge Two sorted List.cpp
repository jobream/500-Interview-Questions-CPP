/*
Date: - 12-06-2020
Author: - AMAN JAIN

Problem : - Merge two sorted List
Question- Link: - https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

Methods:    
    1. Iterative O(n) O(1)  - 
    2. Recursive O(n) O(n) - 

*/

Iterative solution :

Node* sortedMerge(Node* head1,   Node* head2)
{
    if(!head1 && !head2)
        return NULL; 

    else if(!head1)
        return head2;
    
    else if(!head2)
        return head1;
    
    Node* temp=NULL,*head;
    if(head1->data>head2->data){
        temp=head2;
        head=temp;
        head2=head2->next;
    }else{
        temp=head1;
        head=temp;
        head1=head1->next;
    }

    while(head1 && head2){
       if(head1->data>head2->data){
           temp->next=head2;
           temp=head2;
           head2=head2->next;
       }else{
          temp->next=head1;
          temp=head1;
           head1=head1->next;
       }
    }

    if(head1){
      temp->next=head1;
    }else{
       temp->next=head2;
    }
    
    return head;
}



Recursive Solution :

Node *SortedMerge( Node * head1, Node *head2){
    if(head1==NULL)
    return head2;
    else if(head2==NULL)
    return head1;
    
    if(head1->data>head2->data){
           head2->next=SortedMerge(head1,head2->next); 
           return head2;
    }else{
           head1->next=SortedMerge(head1->next,head2); 
           return head1;
    }
    
}

