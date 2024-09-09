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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        ListNode* temp=head;
        int left=0,right=n-1,top=0,bottom=m-1,dir=0;
        vector<vector<int>>ans(m,vector<int>(n));

        while(left<=right && top<=bottom){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    int val;
                    if(temp){
                        val=temp->val;
                        temp=temp->next;
                    }
                    else{
                        val=-1;
                    }
                    ans[top][i]=val; 
                }
                 top++;
            }
            else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    int val;
                    if(temp){
                        val=temp->val;
                        temp=temp->next;
                    }
                    else{
                        val=-1;
                    }
                    ans[i][right]=val;
                }
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    int val;
                    if(temp){
                        val=temp->val;
                        temp=temp->next;
                    }
                    else{
                        val=-1;
                    }
                    ans[bottom][i]=val; 
                }
                bottom--;

            }
            else if(dir==3){
                for(int i=bottom;i>=top;i--){
                    int val;
                    if(temp){
                        val=temp->val;
                        temp=temp->next;
                    }
                    else{
                        val=-1;
                    }
                    ans[i][left]=val; 
                }
                left++;
            }
            dir++;
            dir=dir%4;
            
        }
        return ans;
    }
};