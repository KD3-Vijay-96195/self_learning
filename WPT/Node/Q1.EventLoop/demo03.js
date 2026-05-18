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

async function task3() {
    console.log('Task-3 Started')
    await Promise.resolve()
    console.log('Task-3 InProgress')
    console.log('Task-3 Finished')
}

task3()
task2()
task1()

console.log('end')