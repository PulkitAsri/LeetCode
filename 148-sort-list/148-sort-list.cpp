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
    void printList(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<"->";
            head=head->next;
        }
        cout<<"X"<<endl;
    }
public:
    ListNode* sortTwoSortedLists(ListNode* list1, ListNode* list2){
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        
        ListNode* dummyNode= new ListNode();
        ListNode* headPtr=dummyNode;
        
        ListNode *ptr1= list1;
        ListNode *ptr2= list2;
        
        while(ptr1!=NULL and ptr2!=NULL){
            if(ptr1->val < ptr2->val){
                headPtr->next=ptr1;
                ptr1= ptr1->next;
            }else{
                headPtr->next=ptr2;
                ptr2= ptr2->next;
            }
            headPtr=headPtr->next;
        }
        
        if(ptr1==NULL) headPtr->next = ptr2;
        if(ptr2==NULL) headPtr->next = ptr1;
        
        return dummyNode->next;
        
    }
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        // find mid by turtle approach method  
        ListNode* prev=head;
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow= slow->next;
            fast= fast->next->next;
        }
        
        prev->next=NULL;  
        //disconnect for 2 seperate LinkedList
        
        //call 2 halfs
        ListNode* half1= sortList(head);
        ListNode* half2= sortList(slow);
        
        // printList(half1);
        // printList(half2);
        
        //merge 2 sorted List
        return sortTwoSortedLists(half1, half2);
    }
};