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
    int cntNode(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int cnt=cntNode(head);
        ListNode* temp=head;
        for(int i=0;i<cnt/2;i++){
            temp=temp->next;
        }
        return temp;
    }
};