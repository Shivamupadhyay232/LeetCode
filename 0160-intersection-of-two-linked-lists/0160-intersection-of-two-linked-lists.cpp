/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int cntNode(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=cntNode(headA);
        int n=cntNode(headB);
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        if(m>n){
            for(int i=0;i<m-n;i++){
                temp1=temp1->next;
            }
        }
        else{
            for(int i=0;i<n-m;i++){
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL || temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};