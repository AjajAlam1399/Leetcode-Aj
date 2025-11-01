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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>set;

        for(auto num : nums)set.insert(num);

        ListNode* temp=head;
        ListNode* newHead=NULL;
        ListNode* prev=NULL;

        while(temp){
            int val=temp->val;
            if(set.find(val)==set.end()){
                if(!newHead){
                    newHead=temp;
                    prev=newHead;
                }
                else{
                    prev->next=temp;
                    prev=prev->next;
                }
            }
            temp=temp->next;
        }

        if(prev){
            prev->next=NULL;
        }

        return newHead;
    }
};