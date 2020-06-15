/*
Date: 16-06-2020
Author: Aman Jain

Problem : Intersection of two linked list
Question Link :   https://leetcode.com/problems/intersection-of-two-linked-lists/

(Solution to Leetcode)

*/

Method 1 : (Using difference of node counts)(O(n + m), O(1))

Get count of the nodes in the first list,
let count be c1.Get count of the nodes in the second list,
let count be c2.Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.Then we can traverse both the lists in parallel till we come across a common node.(Note that getting a common node is done by comparing the address of the nodes)

                                                                    class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int countA = 0, countB = 0;
        ListNode *temp = headA;
        while (temp)
        {
            temp = temp->next;
            countA++;
        }

        temp = headB;
        while (temp)
        {
            temp = temp->next;
            countB++;
        }

        if (countB > countA)
        {
            while (countB != countA)
            {
                headB = headB->next;
                countB--;
            }
        }
        else
        {
            while (countA != countB)
            {
                headA = headA->next;
                countA--;
            }
        }

        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return headB;
    }
};

`````````````````````````````````````````````````````````````````````````````````````````````

Method 2: Use hashmaps to store the references of nodes O(n+m) O(n+m)
Traverse list A and store the address / reference to each node in a hash set. Then check every node bi in list B: if bi appears in the hash set, then bi is the intersection node.

Complexity Analysis

Time complexity : O(m+n)O(m+n).

Space complexity : O(m)O(m) or O(n)O(n)

`````````````````````````````````````````````````````````````````````````````````````````````

Method 3: Reversal of list O(n+m) O(n+m)

Just reverse both the linked lists and start matching the node in both the lists.
Once it does not match that indicates previous of this node is the merging node for lists.


`````````````````````````````````````````````````````````````````````````````````````````````

Method 4 : (Good Approach- Two pointer algorithm) O(n+m) O(1)


class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *currA = headA;
        ListNode *currB = headB;
        while (currA || currB)
        {
            if (currA == nullptr && currB != nullptr)
            {
                currA = headB;
            }
            if (currB == nullptr && currA != nullptr)
            {
                currB = headA;
            }
            if (currA == currB)
            {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }

`````````````````````````````````````````````````````````````````````````````````````````````
  
    Method 5 : (Floyd Cycle detection algorithm)

               //USING FLOYD'S CYCLE DETECTION ALGORITHM.
 int intersectPoint(Node *head1, Node *head2)
    {
        Node *temp = head1;
        //REACHING TILL THE END OF THE FIRST LIST.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        //JOINING THE END OF THE 1ST LIST TO THE START OF THE 2ND LIST.
        //IF THERE IS A MERGING POINT PRESENT THEN THIS WILL CREATE AN INNER LOOP.
        temp->next = head2;
        //USE FLOYD'S CYCLE DETETCTION ALGORITHM TO FIND THE STARTING OF THE INNER-LOOP AND THAT WILL BE OUR MERGING POINT.
        Node *slow_ptr = head1, *fast_ptr = head1;
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (slow_ptr == fast_ptr)
            {
                slow_ptr = head1;
                break;
            }
        }
        //IF NO INNER LOOP WAS FORMED ON JOINING THE 1ST LIST'S END AND THE 2ND LITS'S START, THIS MEANS THERE IS NO MERGING POINT.
        if (fast_ptr == NULL || fast_ptr->next == NULL)
        {
            return -1;
        }
        while (1)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            if (slow_ptr == fast_ptr)
            {
                return slow_ptr->data;
            }
        }
    }