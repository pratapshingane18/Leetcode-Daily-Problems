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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *,bool> mp;
        ListNode *curr=head;


        while(curr && mp[curr]==0){

            mp[curr]=1;
            curr=curr->next;


        }
        return curr;
    }
};
