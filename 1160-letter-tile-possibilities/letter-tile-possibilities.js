var numTilePossibilities = function(tiles) {
    let map = {};
    let cnt = 1, n = tiles.length;
    map[1] = cnt;

    // Factorial Precomputation
    for (let i = 2; i <= n; i++) {
        cnt *= i;
        map[i] = cnt;
    }

    // Frequency count of characters
    let stringMap = {};
    for (let i = 0; i < n; i++) {
        if (!stringMap[tiles[i]]) {
            stringMap[tiles[i]] = 0;
        }
        stringMap[tiles[i]]++;
    }

    let arr = Object.values(stringMap);
    let ans = { value: 0 }; // Use an object to store answer

    // Iterate over all lengths
    for (let i = n; i >= 1; i--) {
        fun(0, n-i, map, arr, ans);
    }

    return ans.value;
};

function fun(ind, rem, map, arr, ans) {
    if (ind === arr.length) {
        if (rem === 0) {
            let product = 1;
            let cnt = 0;
            for (let val of arr) {  // Corrected iteration
                if (val > 1) {
                    product *= map[val];
                }
                cnt += val;
            }
            ans.value += map[cnt] / product;  // Update ans correctly
        }
        return;
    }

    // Recursive calls
    fun(ind + 1, rem, map, arr, ans);
    if (arr[ind] > 0) {  // Fixed condition
        arr[ind]--;
        fun(ind, rem - 1, map, arr, ans);
        arr[ind]++; // Backtrack
    }
    return ;
}
