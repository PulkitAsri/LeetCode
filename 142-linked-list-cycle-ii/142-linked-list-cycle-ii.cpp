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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* speedX=head;
        ListNode* speed2X=head;
        
        while(speed2X!=NULL && speed2X->next!=NULL){
            speedX=speedX->next;
            speed2X=speed2X->next->next;
            
            if(speedX==speed2X){
                //Cycle Exist
                //idea: the distance from head to start 
                //== 
                //the distance left in loop
                //(from where theboth pointers meet)
                speedX=head;
                while(speedX!=speed2X){
                    speedX=speedX->next;
                    speed2X=speed2X->next;
                }
                
                return speedX;
                //or speed2X coz both are same(start of loop)
            }
        }
        return NULL;
    }
};