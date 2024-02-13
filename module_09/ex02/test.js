const { execFile } = require('child_process')
const EXECUTABLE = './PmergeMe'

function executeAsyncFile(file, args, callback = () => { }) {
    return new Promise((resolve, reject) => {
        const childProcess = execFile(file, args, (err, data) => {
            if (err) return reject(err)
            return resolve(data)
        })
        callback(childProcess)
    })
}

async function testProgram(arguments, expected) {
    let result = String(await executeAsyncFile(EXECUTABLE, arguments))

    after = result.split('\n')?.[1]?.trim()
    const expct = "After:  " + expected.join(' ').trim()

    if (after === expct) {
        console.log('\x1b[32m%s\x1b[0m', `[SUCCESS]`)
        return;
    }

    console.log('\x1b[31m%s\x1b[0m', `[FAILED]`)
    console.log("RESULT   ", after)
    console.log("EXPECTED ", expct)
}

const generateNumbers = (size = 10) => {
    const getRandomNumber = () => Math.round(Math.random() * 10000)
    let array = []

    for (let i = 0; i < size; i++) {
        let random = getRandomNumber()

        do random = getRandomNumber()
        while (array.filter(n => n === random).length !== 0)

        array.push(random)
    }
    return array
}

function generateRandomArguments(size) {
    const arguments = generateNumbers(size)
    return {
        expected: [...arguments].sort((a, b) => a - b),
        arguments
    }
}

async function init() {
    for (let i = 1; i <= 10001; i += 100) {
        console.log('\x1b[34m%s\x1b[0m', `[INFO]    Size: ${i}`)
        const { arguments, expected } = generateRandomArguments(i)
        await testProgram(arguments, expected)
    }
}

init()
