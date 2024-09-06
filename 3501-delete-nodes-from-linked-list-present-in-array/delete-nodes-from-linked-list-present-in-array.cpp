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
        int n=nums.size();
        unordered_set<int>set;
        for(int i=0;i<n;i++){
            set.insert(nums[i]);
        }
        ListNode* newHead=NULL;
        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp){
            int val=temp->val;
            if(set.find(val)!=set.end()){

            }
            else{
                if(!newHead){
                    newHead=temp;
                    prev=temp;
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