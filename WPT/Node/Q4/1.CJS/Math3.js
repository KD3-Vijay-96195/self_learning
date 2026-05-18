function add(n1, n2) {
    const res = n1 + n2
    console.log('Addition - ' + res)
}

function sub(n1, n2) {
    const res = n1 - n2
    console.log('Substraction - ' + res)
}

function mul(n1, n2) {
    const res = n1 * n2
    console.log('Multiplication - ' + res)
}

module.exports = add
module.exports.sub = sub
module.exports.multiply = mul