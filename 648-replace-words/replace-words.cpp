class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>set;

        for(int i=0;i<dictionary.size();i++){
            set.insert(dictionary[i]);
        }
        
        queue<string>q;
        int i=0,n=sentence.size();
        string str="";
        while(i<n){
            while(i<n && sentence[i]!=' '){
                str+=sentence[i];
                i++;
            }
            if(str.size()>0){
                q.push(str);
                str="";
            }
            i++;
        }
        string ans="";
        while(!q.empty()){
            str=q.front();
            q.pop();
            bool flag=false;
            for(int i=0;i<str.size();i++){
                if(set.find(str.substr(0,i+1))!=set.end()){
                    ans+=str.substr(0,i+1)+" ";
                    flag=true;
                    break;
                }
            }
            if(!flag)ans+=str+" ";
        }
        ans.pop_back();
        return ans;
    }
};