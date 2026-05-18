function createResult(error, data){
    const result = {}
    if(data){
        result.status = 'success'
        result.data = data
    }
    else{
        result.status = 'error'
        result.error = error
    }
    return result
}

function successResult(data){
    return createResult(null, data)
}

function errorResult(error){
    return createResult(error, null)
}

module.exports = {successResult, errorResult}