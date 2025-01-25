/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let maxi = -1e8;
    for(i of candies){
        maxi = Math.max(maxi,i);
    }
    console.log(maxi);
    var res = [];
    for(i of candies){
        if((i + extraCandies) >= maxi){
            res.push(true);
        }
        else{
            res.push(false);
        }
    }

    return res;
};