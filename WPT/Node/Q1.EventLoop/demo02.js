console.log('Start')

function task1() {
    console.log('Task-1 Started')
    Promise.resolve().then(() => {
        console.log('Task-1 InProgress')
        console.log('Task-1 Finished')
    })

}

function task2() {
    console.log('Task-2 Started')
    setTimeout(() => {
        console.log('Task-2 InProgress')
        console.log('Task-2 Finished')
    }, 0)

}

function task3() {
    console.log('Task-3 Started')
    Promise.resolve().then(() => {
        console.log('Task-3 InProgress')
        console.log('Task-3 Finished')
    })
}

task1()
task2()
task3()

console.log('end')