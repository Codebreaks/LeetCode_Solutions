/*
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (28.19%)
 * Total Accepted:    126K
 * Total Submissions: 447.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * 
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
 void reorderList(ListNode* head) 
 {
	 ListNode* slow = head;
	 ListNode* fast = head;
     ListNode* pre = NULL;
     if(!head || head->next == NULL) return ;

	 while (fast != NULL && fast->next != NULL)
	 {
		 pre = slow;
         slow = slow->next;
		 fast = fast->next->next;
        
	 }
     
     //odd
     if(fast && fast->next == NULL)
     {
         pre = slow;
         slow = slow->next;
     }
     
     pre->next = NULL;
     
	 stack<ListNode*> tempholder;

	 while (slow != NULL)
	 {
		 tempholder.push(slow);
		 slow = slow->next;   
	 }
	 

	 ListNode* returnhead = head;

	 while (!tempholder.empty())
	 {
		 ListNode* temp = tempholder.top();
         // cout << "1";
		 temp->next = head->next;
		 // cout << "2";
         head->next = temp;
		 // cout << "3";
         head = temp->next;
         // cout << "4";
         tempholder.pop();
         // cout << "5";
         if(tempholder.empty() && fast==NULL) temp->next = NULL;
	 }
     
	 head = returnhead;
 }
};
