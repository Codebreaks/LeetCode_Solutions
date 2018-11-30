/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (30.37%)
 * Total Accepted:    273.5K
 * Total Submissions: 900.7K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                return l1->next = mergeTwoLists(l1->next, l2);
            }
            else
            {
                return l2->next = mergeTwoLists(l1, l2->next);
            }

            return (l1 == NULL) ? l2 : l1;
        }
        return NULL;
    }

    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (!lists.size()) return NULL;
        ListNode* Merged = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            Merged = mergeTwoLists(Merged, lists[i]);
            cout << Merged->val << endl;
        }
        return Merged;
    }
    
    
};
