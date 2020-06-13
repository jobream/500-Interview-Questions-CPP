/*
Date: 13-06-2020
Author: Aman Jain

Problem : Reverse A linked list (Iterative)
Question Link :   https://leetcode.com/problems/reverse-linked-list/


(Solution to Leetcode)

*/ 



ListNode* reverseList(ListNode* head) {
        ListNode * temp=NULL,*temp1=NULL;
        while(head){
            temp1=temp;
            temp=head;
            head=head->next;
            temp->next=temp1;
        }
        return temp;      
    }