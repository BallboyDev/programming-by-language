const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

rl.on('line', (line) => {
    console.log(arith(1 * line))

    rl.close()
}).on('close', () => {

})

let arith = (line) => {
    let count = 0;
    for (let index = 1; index <= line; index++) {
        if (index < 100) {
            count++
        } else {
            let diff = 0;
            count += ('' + index).split('').every((v, i, a) => {
                // console.log(v - a[i + 1])
                if (i === 0) {
                    diff = v - a[i + 1]
                    return true
                    // return true
                } else if (i === a.length - 1) {
                    return true
                    // return true
                } else {
                    return diff === (v - a[i + 1])
                }

            }) ? 1 : 0
        }
    }
    return count
}