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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp1=head;
        
        ListNode* temp2=head;
        ListNode* prev=NULL;
        ListNode* prev2=dummy;

        for(int i=1;i<left;i++){
            prev2=temp1;
            temp1=temp1->next;
            
        }
        ListNode* sec=temp1->next;
        for(int i=1;i<right;i++){
            temp2=temp2->next;
            
        }
        
        while(temp1!=temp2){
            temp1->next=prev;
            prev=temp1;
            temp1=sec;
            sec=sec->next;
        }
        temp1->next=prev;
        prev2->next->next=sec;
        prev2->next=temp1;
        return dummy->next;
    }
};