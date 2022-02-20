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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* newHead=new ListNode(0);
        ListNode* ptr=head;
        ListNode* newPtr=newHead;
        
        
        while(ptr->next!=NULL){
            if(ptr->val!=0){
                newPtr->val+=  ptr->val;
            }else{
                newPtr->next =new ListNode(0);
                newPtr= newPtr->next;
            }
            ptr=ptr->next;
        }
        
        return newHead->next;
        
    }
};