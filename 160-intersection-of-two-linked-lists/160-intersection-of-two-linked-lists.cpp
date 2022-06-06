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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int na=0; ListNode* ptrA=headA;
        while(ptrA!= NULL){
            na++;
            ptrA=ptrA->next;
        }
        int nb=0; ListNode* ptrB=headB;
        while(ptrB!= NULL){
            nb++;
            ptrB=ptrB->next;
        }
        
        ptrA=headA;
        ptrB=headB;
        if(na > nb){
            while(na!=nb){
                na--;
                ptrA=ptrA->next;
            }
        }else if(nb > na){
            while(na!=nb){
                nb--;
                ptrB=ptrB->next;
            }
        }
        
        while(ptrA!= NULL && ptrA!= ptrB){
            ptrA=ptrA->next;
            ptrB=ptrB->next;
        }
        
        return ptrA;
        
    }
};