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
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead=reverse(head);
        ListNode* temp=newHead;
        ListNode* prev;
        int carry=0;

        while(temp){
            int val=temp->val*2+carry;
            carry=val/10;
            temp->val=val%10;
            prev=temp;
            temp=temp->next;
        }
        if(carry){
            prev->next=new ListNode(carry);
        }
        return reverse(newHead);
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};