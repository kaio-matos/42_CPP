const { execFile } = require('child_process')
const EXECUTABLE = './RPN'
const VALGRIND_EXECUTABLE = 'valgrind'
const VALGRIND_FLAGS = ['--leak-check=full', '--error-exitcode=1']

function executeAsyncFile(file, args, callback = () => { }) {
    return new Promise((resolve, reject) => {
        const childProcess = execFile(file, args, (err, data) => {
            if (err) return reject(err)
            return resolve(data)
        })
        callback(childProcess)
    })
}

async function testProgram(expression, expected) {
    const checkSuccess = (result) => {
        if (result === expected) {
            console.log('\x1b[32m%s\x1b[0m', `[SUCCESS]  = ${result}`)
        } else {
            console.log('\x1b[31m%s\x1b[0m', `[FAILED]   Received '${result}' | Expected: '${expected}'`)
        }
    }

    try {
        let result = String(await executeAsyncFile(EXECUTABLE, expression ? [expression] : undefined))
        result = result.replace('\n', '')
        console.log(`EXPRESSION ${expression}`)
        checkSuccess(result)
    } catch (error) {
        const result = error.message.replace('Command failed: ./RPN\n', '').replace('\n', '')
        checkSuccess(result)
    }

    try {
        await executeAsyncFile(VALGRIND_EXECUTABLE, [...VALGRIND_FLAGS, EXECUTABLE, expression])
        console.log('\x1b[32m%s\x1b[0m', `[SUCCESS]  Memory Check`)
    } catch (error) {
        if (error.code === 1) {
            console.log('\x1b[31m%s\x1b[0m', `[FAILED]   Memory Check`)
        }
    }

    console.log("")
}

async function init() {
    await testProgram("", "Bad arguments")
    await testProgram("1", "1")
    await testProgram("1321", "1321")
    await testProgram("8 9 * 9 - 9 - 9 - 4 - 1 +", "42")
    await testProgram("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -", "42")
    await testProgram("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /", "15")
    await testProgram("7 7 * 7 -", "42")
    await testProgram("1 2 * 2 / 2 * 2 4 - +", "0")
    await testProgram("(1 + 1)", "Error") // invalid expression

    await testProgram("3 4 + 5 *", "35")
    await testProgram("10 2 / 3 *", "15")
    await testProgram("8 2 * 4 /", "4")
    await testProgram("5 2 - 7 +", "10")
    await testProgram("12 3 * 4 2 * -", "28")
    await testProgram("6 3 * 2 +", "20");
    await testProgram("10 5 / 2 *", "4");
    await testProgram("15 4 + 3 -", "16");
    await testProgram("9 3 / 2 *", "6");
    await testProgram("7 2 * 3 /", "4");

    await testProgram("1 2 + 3 -", "0")
    await testProgram("10 6 9 3 + -11 * / * 17 + 5 +", "22")
    await testProgram("1 3 2 + 3 -", "Error") // invalid expression
    await testProgram("1 3 + + 3 -", "Error") // invalid expression
    await testProgram("1 3 3 3 3 -", "Error") // invalid expression
    await testProgram("1 / / / / / / / /", "Error") // invalid expression
    await testProgram("1 3 21 / * * / / / /", "Error") // invalid expression
    await testProgram("2 2 + +", "Error") // invalid expression
    await testProgram("10 [10] *", "Error") // invalid expression
    await testProgram("[10 10 *", "Error") // invalid expression
    await testProgram("d10 10 *", "Error") // invalid expression
    await testProgram("10 10 *a", "Error") // invalid expression
    await testProgram("0 0 /", "Error") // invalid calculation
    await testProgram("10 0 /", "Error") // invalid calculation
    await testProgram("10 10 /", "1")
    await testProgram("1 3 2 + * 3 -", "2")
    await testProgram("8 2 * 4 /", "4");
    await testProgram("5 2 - 7 +", "10");
    await testProgram("12 3 * 4 2 * -", "28");
    await testProgram("4 2 / 3 *", "6");
    await testProgram("9 3 / 2 *", "6");
    await testProgram("10 2 / 3 *", "15");
    await testProgram("5 3 + 2 *", "16");
    await testProgram("7 2 * 4 2 + *", "84");
    await testProgram("20 4 / 2 *", "10");
    await testProgram("8 4 / 2 *", "4");
    await testProgram("8 4 / 2 *", "4");

}

init()
