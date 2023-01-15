'use strict'

const bar = () => console.log('bar');
const baz = () => console.log('baz');

const foo = async () => {
    console.log('foo');
    setTimeout(bar, 0);
    new Promise((resolve, reject) => resolve('should be right after baz, before bar'))
    .then(resolve=>console.log(resolve))
    // console.log('hoo');
    baz();
}

foo();

setInterval(()=>console.log("timed out!"), 1000);
