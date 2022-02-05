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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL && list2==NULL){
            return NULL;
        }else if(list1==NULL){
            return list2;
        }else if(list2==NULL){
            return list1;
        }
        
        ListNode* head =new ListNode();
        ListNode* headPtr=head;
        
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val < ptr2->val){
                headPtr->next=ptr1;
                ptr1=ptr1->next;
            }else{
                headPtr->next=ptr2;
                ptr2=ptr2->next;
            }
            headPtr=headPtr->next;
        }
        
        if(ptr1==NULL) headPtr->next=ptr2;
        if(ptr2==NULL) headPtr->next=ptr1;
        
        return head->next;
    }
};