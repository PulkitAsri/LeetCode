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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        ListNode* prev=dummy;
        
        for(int i=0; i<k; i++){
            prev=fast;
            fast=fast->next;
        }
        

        ListNode* kFromStart=fast;
        ListNode* prev2=dummy;
        
        while(fast!=NULL){
            prev2=slow;
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* kFromEnd=slow;
        
        // cout<<prev->val<<" "<<kFromStart->val;
        // cout<<prev2->val<<" "<<kFromEnd->val<<endl;
        
        
        prev->next=kFromEnd;
        ListNode* temp=kFromEnd->next;
        prev2->next=kFromStart;
        kFromEnd->next=kFromStart->next;
        kFromStart->next=temp;
        
        return dummy->next;
        
    }
};