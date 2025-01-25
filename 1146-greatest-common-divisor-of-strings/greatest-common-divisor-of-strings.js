/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    if(str1 + str2 != str2 + str1) return "";

    let n1 = str1.length;
    let n2 = str2.length;

    let gcd = function(n1,n2){
        if(!n2){
            return n1;
        }
        return gcd(n2,n1%n2);
    }

    let div = gcd(n1,n2);

    return str1.slice(0,div);
};