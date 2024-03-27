const { execFile } = require('child_process')
const EXECUTABLE = './PmergeMe'
const VALGRIND_EXECUTABLE = 'valgrind'
const VALGRIND_EXIT_CODE = 200
const VALGRIND_FLAGS = ['--leak-check=full', '--error-exitcode=' + VALGRIND_EXIT_CODE]
const COLORS = {
    GREEN: '\x1b[32m%s\x1b[0m',
    RED: '\x1b[31m%s\x1b[0m',
    BLUE: '\x1b[34m%s\x1b[0m',
}

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
    const fail = (received) => {
        console.log(COLORS.RED, `[FAILED]`)
        console.log("RESULT   ", received)
        console.log("EXPECTED ", expected)
    }
    try {

        let result = String(await executeAsyncFile(EXECUTABLE, arguments))

        after = result.split('\n')?.[1]?.trim()

        if (after === expected) {
            console.log(COLORS.GREEN, `[SUCCESS]`)
            return;
        }

        fail(after)
    } catch (error) {
        const result = error.message.split('\n')[1].replace('\n', '')

        if (result === expected) {
            console.log(COLORS.GREEN, `[SUCCESS]`)
            return
        }
        fail(result)
    }

}

async function testProgramValgrind(arguments, expected) {
    try {
        await executeAsyncFile(VALGRIND_EXECUTABLE, [...VALGRIND_FLAGS, EXECUTABLE, ...arguments])
        console.log(COLORS.GREEN, `[SUCCESS]  Memory Check`)
    } catch (error) {
        if (error.code === VALGRIND_EXIT_CODE) {
            console.log(COLORS.RED, `[FAILED]   Memory Check`)
        } else {
            console.log(COLORS.GREEN, `[SUCCESS]  Memory Check`)
        }
    }
}

const generateNumbers = (size = 10) => {
    return Array.from(Array(size), () => Math.round(Math.random() * 10000))
}

function generateRandomArguments(size) {
    const arguments = generateNumbers(size)
    return {
        expected: toExpectedFormat([...arguments].sort((a, b) => a - b)),
        arguments
    }
}

function toExpectedFormat(exptectedArray) {
    return "After:  " + exptectedArray.join(' ').trim()
}

async function init() {
    const test = (arguments, expected) => Promise.all([testProgram(arguments, expected), testProgramValgrind(arguments, expected)])
    const manualTest = async (arguments, expected) => {
        if (!expected) {
            expected = toExpectedFormat([...arguments].sort((a, b) => a - b))
        }
        console.log(COLORS.BLUE, `[INFO] '${arguments.join(' ')}' -> '${expected}'`)
        await test(arguments, expected)
    }

    await manualTest([3, 5, 9, 7, 4])
    await manualTest([3.321, 5.312, 9.23, 7.44, 4.2], "Bad arguments")
    await manualTest([1])
    await manualTest([0])
    await manualTest([], "Bad arguments")
    await manualTest(['d'], "Bad arguments")
    await manualTest(['d', 'f'], "Bad arguments")
    await manualTest([2, 'f'], "Bad arguments")
    await manualTest([4, 2.33], "Bad arguments")
    await manualTest([-10, -3, -2], "Bad arguments")
    await manualTest([-1, -2, -3], "Bad arguments")
    await manualTest([-3, -2, -1], "Bad arguments")
    await manualTest(["-0"], "Bad arguments")


    for (let i = 1; i <= 10001; i += 100) {
        console.log(COLORS.BLUE, `[INFO]     Size: ${i}`)
        const { arguments, expected } = generateRandomArguments(i)
        await test(arguments, expected)
    }
}

init()
