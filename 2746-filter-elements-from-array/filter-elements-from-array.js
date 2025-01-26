/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let res = [];
    for(let i=0;i<arr.length;i++){
        let x = fn(arr[i],i);
        if(Boolean(x) === true){
            res.push(arr[i]);
        }
    }

    return res;
};