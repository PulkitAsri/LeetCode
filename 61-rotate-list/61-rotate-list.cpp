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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n=0;
        ListNode* ptr=head;
        while(ptr){
            n++;
            ptr=ptr->next;
        }
        if(n==0) return head;

        k%=n;
        
        if(k==0) return head;
        
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(k--) fast=fast->next;
    
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
        
    }
};