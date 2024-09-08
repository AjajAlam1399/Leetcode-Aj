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
    int size(ListNode* head){
        ListNode* temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        return size;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=size(head);
        int el=len/k;
        int mod=len%k;
        ListNode* temp=head;
        vector<ListNode*>ans(k);
        int ind=0;

        while(temp){
            ListNode* newHead=temp;
            int loop=el;
            if(mod>0){
                loop+=1;
            }
            int cnt=0;

            ListNode* prev=temp;
            while(temp && cnt<loop){
                prev=temp;
                temp=temp->next;
                cnt++;
            }
            ans[ind]=newHead;
            ind++;
            if(prev){
                prev->next=NULL;
            }
            mod--;
        }
        return ans;
    }
};