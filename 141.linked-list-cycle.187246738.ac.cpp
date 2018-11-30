/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (34.62%)
 * Total Accepted:    302K
 * Total Submissions: 872.2K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
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
    
bool hasCycle(ListNode *head) {
	if (!head) return false;

	ListNode* slow = head;
	ListNode* fast = head;
    bool first = true;

	while (slow != NULL && fast != NULL)
	{
        
		slow = slow->next;

		if (fast->next )
		{
		    fast = fast->next->next;	
		}
        else
            return false;
        
       if (slow == fast) return true;

	}
	return false;
}
    
};
