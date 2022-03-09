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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // if(!head) return head;
        ListNode* dummy = new ListNode(INT_MIN);
        // dummy->next = head;
        ListNode* prev= dummy;
        ListNode* ptr= head;

        while(ptr){
            // cout<<prev->val<<" "<<ptr->val<<endl;
            auto start = ptr;
            int count = 0;
            // if(ptr->val == ptr->next->val){
            while(ptr && ptr->val == start->val){
                ptr=ptr->next;
                count++;
            }
            if(count == 1) {
                
                prev -> next = start;
                prev = start;
                prev -> next = NULL;
            }
                // if(!ptr){
                //     prev->next=NULL;
                //     break;
                // }else{
                //     prev->next=ptr->next;
                // }
            // }else{
                // prev=ptr;
            // }
            // ptr=ptr->next;
        }
        
        return dummy->next;
        
    }
};