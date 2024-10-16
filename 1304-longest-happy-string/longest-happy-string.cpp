class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        queue<pair<int,char>>q;
        if(a>0){
            q.push({a,'a'});
        }
        if(b>0){
            q.push({b,'b'});
        }
        if(c>0){
            q.push({c,'c'});
        }
        string ans="";
        while(q.size()>1){
            auto it=q.front();
            q.pop();
            ans.push_back(it.second);
            if(it.first-1>0){
                q.push({it.first-1,it.second});
            }
        }
        int rem=0;
        char ch;
        if(!q.empty()){
            auto it=q.front();
            q.pop();
            rem=it.first;
            ch=it.second;
        }
        while(rem){
            bool flag=false;
            if(ans.size()==0){
                ans.push_back(ch);
                rem--;
                flag=true;
            }
            else if(ans.size()==1){
                ans.push_back(ch);
                rem--;
                flag=true;
            }
            else{
                for(int i=0;i<ans.size();i++){
                    char ch1='0';
                    char ch2='1';
                    if(ans[i]!=ch){
                        if(i-2>=0){
                            ch1=ans[i-2];
                        }
                        if(i-1>=0){
                            ch2=ans[i-1];
                        }
                        if(ch1!=ch || ch2!=ch){
                            ans=ans.substr(0,i)+ch+ans.substr(i);
                            rem--;
                            flag=true;
                            break;
                        }
                    }
                }
            }
            if(rem==0 || !flag){
                break;
            }
        }
        while(rem){
            char ch1='0';
            char ch2='1';
            int n=ans.size();
            if(n-1>=0){
                ch1=ans[n-1];
            }
            if(n-2>=0){
                ch2=ans[n-2];
            }
            if(ch1!=ch || ch2!=ch){
                ans.push_back(ch);
                rem--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};