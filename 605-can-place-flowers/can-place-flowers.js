/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    if(flowerbed.length == 1 ){
        if(flowerbed[0] == 1 && n == 1) return false;
        else return true;
    }

    let count = 0;

    for(let i=0;i<flowerbed.length;i++){
        if(i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
            count++;
            i++;
        }
        else if(i == flowerbed.length-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0){
            count++;
        }
        else if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
            count++;
            i++;
        }
    }

    if(n <= count) return true;
     
    return false;
};