/*
Date: 14-06-2020
Author: Aman Jain

Problem : Remove duplicates from a sorted list
Question Link :   https://leetcode.com/problems/remove-duplicates-from-sorted-list/


(Solution to Leetcode)

*/ 

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) 
	{
		if(!head) return head;
		ListNode *curr = head;
		while(curr)
		{
			if(!curr->next) break;
			if(curr->val == curr->next->val)
				curr->next = curr->next->next;
			else
				curr = curr->next;
		}
		return head;
	
};