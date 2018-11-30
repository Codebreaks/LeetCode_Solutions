/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.75%)
 * Total Accepted:    229.7K
 * Total Submissions: 747.1K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int getLength(ListNode* head)
{
	if (head) return 1 + getLength(head->next);
	return 0;
}
    
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int lenA = getLength(headA);
	int lenB = getLength(headB);

	if (lenA > lenB)
	{
		int diff = lenA - lenB;
		while (diff)
		{
			headA = headA->next;
            diff--;
		}
	}
    
	if (lenB > lenA)
	{
		int diff = lenB - lenA;
		while (diff)
		{
			headB = headB->next;
            diff--;
		}
	}

	while (headA != NULL)
	{
		if (headA == headB) return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return headA;
}
};
