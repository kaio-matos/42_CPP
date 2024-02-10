const { execFile } = require('child_process')
const EXECUTABLE = './RPN'

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
    let result = String(await executeAsyncFile(EXECUTABLE, [expression]))

    result = result.replace('\n', '')

    if (result === expected) {
        console.log('\x1b[32m%s\x1b[0m', `[SUCCESS] ${expression} = ${result}`)
        return;
    }

    console.log('\x1b[31m%s\x1b[0m', `[FAILED]  ${expression} = ${result} | Expected: '${expected}', received '${result}'`)
}

async function init() {
    await testProgram("8 9 * 9 - 9 - 9 - 4 - 1 +", "42")
    await testProgram("7 7 * 7 -", "42")
    await testProgram("1 2 * 2 / 2 * 2 4 - +", "0")
    await testProgram("(1 + 1)", "Error")

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

}

init()
