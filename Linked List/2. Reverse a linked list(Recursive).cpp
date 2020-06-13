/*
Date: 13-06-2020
Author: Aman Jain

Problem : Reverse A linked list (Recursive)
Question Link :   https://leetcode.com/problems/reverse-linked-list/


(Solution to Leetcode)

*/ 
   ListNode * reverseListUtil(ListNode * &head,ListNode *&temp,ListNode *&temp1){
        
        if(head==NULL)
            return temp;
        
        temp1=temp;
        temp=head;
        head=head->next;
        temp->next=temp1;
        
        return reverseListUtil(head,temp,temp1);
                
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=NULL,*temp1=NULL;
        return reverseListUtil(head,temp,temp1);
           
    }