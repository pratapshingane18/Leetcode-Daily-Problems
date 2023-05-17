/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
      // take stack store all values in stack
      stack<int> st;

      ListNode* temp = head;

      while(temp){
          st.push(temp->val);
          temp = temp->next;
      }
    temp = head;
      int maxi = 0;

      while(temp){
          maxi = max(maxi, st.top()+temp->val);
          temp= temp->next;
          st.pop();
      }

      return maxi;
    }
};


/*
 // take node to traverse
       ListNode* temp = head;

       // defining vectir to store values
       vector<int> res;

       // traversing
       while(head){
           res.push_back(temp->val);
           temp = temp->next;

       }
    // variables for storing value
       int max =0;
        int curr =0;
        int n = res.size();

    
       for(int i=0; i < n/2; i++){
           curr = res[i] + res[n-i-1];
           if(curr>max){
               max = curr;
           }
       }

       return max;

       */
