/**
 * @return {Function}
 */
var createHelloWorld = function() {
    let x = "Hello World"
    return function(...args) {
        return x;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */