/*
Date: 19-06-2020
Author: Aman Jain

Problem : Palindrome Linked List
Question Link : https://leetcode.com/problems/palindrome-linked-list/

(Solution to Leetcode)

*/

Method 1 : Using stacks(Two traversal)

               class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *temp = head;
        while (temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            if (temp->val != st.top())
                return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};

Method 2 : Using recursion (Two pointer algorithm)

 class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prevv = NULL;
        ListNode *temp = NULL;
        while (current)
        {
            temp = current->next;
            current->next = prevv;
            prevv = current;
            current = temp;
        }
        return prevv;
    }

    bool isPalindrome(ListNode *head)
    {
        //first get to the middle, then reverse the second half, and then compare these two
        if (head == NULL)
        {
            return true;
        }
        ListNode *hare = head;
        ListNode *tortoise = head;
        ListNode *previous = head;
        while (hare && hare->next)
        {
            previous = tortoise;
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        previous->next = NULL;
        ListNode *revhead = reverse(tortoise);
        while (head && revhead)
        {
            if (head->val == revhead->val)
            {
                head = head->next;
                revhead = revhead->next;
            }
            else
            {
                return false;
            }
        }
        return true;



