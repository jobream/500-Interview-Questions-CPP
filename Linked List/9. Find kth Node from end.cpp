/*
Date: 25-06-2020
Author: Aman Jain

Problem : Find Kth Node from end
Question Link :  https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
(Solution to Geeks for geeks)

*/

Method - 1(Two traversals, calculating lenght of list) int getNthFromLast(Node *head, int n)
{
    Node *p = head;
    if (head == NULL)
        return NULL;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    p = head;
    if (count < n)
        return -1;
    count = count - n;
    while (count--)
    {
        p = p->next;
    }
    return p->data;
}


Method -2 (One traversal) -Two pointer algorithm
int getNthFromLast(Node *head, int n)
{
       Node * temp=head;
       while(n-- && temp){
           temp=temp->next;
       }
       if(!temp &&n>=0)
       return -1;
       
       Node * temp2=head;
       while(temp!=NULL){
           temp2=temp2->next;
           temp=temp->next;
       }
       
       return temp2->data;
}

Method -3 (Recursive)

void printNthFromLast(struct Node* head, int n)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, n);
    if (++i == n)
        printf("%d", head->data);
}