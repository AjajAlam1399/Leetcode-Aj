class Solution {
public:
    int reverse(int x) {
      
       string str=to_string(x);
       std::reverse(str.begin(),str.end());
       int num =0;
       for(int i=0;i<str.size();i++){
        if(str[i]=='-')continue;
        long long val;
        if(x>=0){
            val=(long long)num*10+str[i]-'0';
            if(val>INT_MAX)return 0;
        }
        else{
           val=(long long)num*10-(str[i]-'0'); 
           if(val<INT_MIN) return 0;
        }
        
        num=val;
        // if(num<0)return 0;
       }
       return num;
    }
};