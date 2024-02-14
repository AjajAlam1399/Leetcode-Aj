class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        queue<int>neg;
        queue<int>pos;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                neg.push(arr[i]);
            }
            if(arr[i]>0){
                pos.push(arr[i]);
            }
        }
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                arr[i]=pos.front();
                pos.pop();
            }
            else if(i%2!=0){
                arr[i]=neg.front();
                neg.pop();
            }
        }
        return arr;
        
        
    }
};