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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
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
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        
        for(int i=1; i<k; i++){
            lists[i]=mergeTwoLists(lists[i-1], lists[i]);
        }
        
        return lists[k-1];
        
    }
};