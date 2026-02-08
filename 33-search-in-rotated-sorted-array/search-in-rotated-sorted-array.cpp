class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int s=0,e=n-1;

        while(s<=e){
            int mid= (s+e)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]>=arr[s]){
                if(arr[s]<=target && target<arr[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else {
                if(arr[e]>=target && target>arr[mid]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }

        return -1;
    }
};