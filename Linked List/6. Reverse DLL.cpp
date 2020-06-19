/*
Date: 19-06-2020
Author: Aman Jain

Problem : Reverse a doubly linked list
Question Link :   https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

(Solution to geeks for geeks)

*/

Node* reverseDLL(Node * head){
   Node *p=head,*q=NULL,*t=NULL;
   while(p){
       q=t;
       t=p;
       p=p->next;
       t->next=q;
       t->prev=p;
   }
   return t;
   
}