class Solution {
    int countNode(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;

        int k = countNode(head);

        if(k == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;

        for(int i = 0; i < k-n-1; i++){
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};