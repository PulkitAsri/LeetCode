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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        
        ListNode *head=NULL;
        ListNode *ptr=head;
        while(l1 || l2){
            int x1=0,x2=0;
            if(l1) x1=l1->val;
            if(l2) x2=l2->val;
            
            int crtValue=(x1+x2+carry)%10;
            carry=(x1+x2+carry)/10;
            
            ListNode* currNode=new ListNode(crtValue);
            if(!head) head=ptr=currNode;
            else ptr->next=currNode;
    
            
            ptr=currNode;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next; 
        }
        
        if(carry){
            ptr->next=new ListNode(carry);
        }else{
            ptr->next=NULL;
        }
        
        return head;
        
    }
};