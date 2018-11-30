/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.61%)
 * Total Accepted:    183.6K
 * Total Submissions: 716.9K
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    

RandomListNode *copyRandomList(RandomListNode *head)
{
	RandomListNode* l1 = NULL;
	RandomListNode* l2 = NULL;
	RandomListNode* newHead = NULL;

    if (!head) return newHead;

    for (l1 = head; l1 != NULL; l1 = l1->next->next)
    {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }
    newHead = head->next;

    for (l1 = head; l1 != NULL; l1 = l1->next->next)
    {
        l1->next->random = (l1->random != NULL) ? l1->random->next : NULL;
    }

    l2 = head->next;

    for (l1 = head; l1 != NULL; l1 = l1->next)
    {
        l1->next = l1->next->next;
        l1->next != NULL ? l2->next = l1->next->next : l2->next = NULL;
        l2 = l2->next;
    }

    
	return newHead;
}
    
};
