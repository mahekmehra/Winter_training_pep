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
    ListNode* middleNode(ListNode* head) {


        /*ListNode* temp = head;
        int len = 0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
    
        }
        
        int node = (len/2);
        temp=head;
        for(int i=0;i<node;i++){
            temp=temp->next;
        }

        return temp;*/



        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
        
    }
};