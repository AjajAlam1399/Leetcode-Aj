/**
 * @param {string} pattern
 * @return {string}
 */
var smallestNumber = function(pattern) {
    let ans=[];
    let bitMask={
        value:0
    }

    for(let i=1;i<=9;i++){
        ans.push(i);
        bitMask.value|=1<<i;
        if(fun(0,bitMask,pattern,ans)){
            break;
        }
        ans.pop();
        bitMask.value=bitMask.value&(~(1<<i));
    }

    return ans.join("");
};

function fun(ind,bitMask,pattern,ans){
    if(ind===pattern.length){
        return true;
    }
    for(let i=1;i<=9;i++){
        let bit=(bitMask.value)&(1<<i);
        if(!bit){
            
            if((pattern[ind]==='I' && i>(ans.at(-1)))||
            (pattern[ind]==='D' && i<(ans.at(-1)))){
                ans.push(i);
                bitMask.value|=1<<i;
                if(fun(ind+1,bitMask,pattern,ans)){
                    return true;
                }
                ans.pop();
                bitMask.value=bitMask.value&(~(1<<i));
            }
        }
    }
    return false;
}