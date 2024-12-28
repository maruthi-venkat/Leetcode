/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var arr = [];
    for(let i=0;i<nums.length;i++){
        for(let j=i+1;j<nums.length;j++){
            if(nums[j] == target - nums[i]){
                arr[0] = i;
                arr[1] = j;

                break;
            }
        }
    }

    return arr;
};