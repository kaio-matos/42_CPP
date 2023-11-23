/**
 * helpers
 */
const sum = (n1, n2) => n1 + n2


/**
 * IEEE 754 standard
 *
 * Based on:
 * - https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
 * - https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html
 * - https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html
 * - https://mathcenter.oxford.emory.edu/site/cs170/ieee754/
 *
 * <br>
 *
 * The simplest implementation of the world for study purposes
 *
 * For a true implementation
 * @see https://www.azabani.com/labs/floatvis
 * @see https://www.azabani.com/labs/floatvis/script.js
 */

class Float32 {
    standard = { sign: 's', exponent: 'eeeeeeee', mantissa: 'mmmmmmmmmmmmmmmmmmmmmmm' }
    bias = 0x7f // 127
    /** @type string */
    sign
    /** @type string */
    exponent
    /** @type string */
    mantissa

    constructor(sign, exponent, mantissa) {
        if (sign.length != 1) throw new Error(`Sign must have 1 bit, it has ${sign.length}`)
        if (exponent.length != 8) throw new Error(`Exponent must have 8 bits, it has ${exponent.length}`)
        if (mantissa.length != 23) throw new Error(`Mantissa must have 23 bits, it has ${mantissa.length}`)

        this.sign = sign
        this.exponent = exponent
        this.mantissa = mantissa
    }

    getValue() {
        const sign = Math.pow(-1, Number(this.sign))
        const exponent = [...this.exponent].map(Number)
        const mantissa = [...this.mantissa].map(Number)


        const isExponentAllOneBits = !exponent.filter(v => v !== 1).length
        const isExponentAllZeroBits = Boolean(exponent.filter(v => v !== 1).length)
        const isMantissaAllZeroBits = Boolean(mantissa.filter(v => v !== 1).length)

        /**
         * Special  Cases
         */

        /**
         * Zero
         * Sign bit = 0;
         * biased exponent = all 0 bits;
         * and the fraction = all 0 bits;
         */
        if (isExponentAllZeroBits && isMantissaAllZeroBits) return 0

        /**
         * NaN (Not-A-Number)
         * Sign bit = 0 or 1;
         * biased exponent = all 1 bits;
         * and the fraction is anything but all 0 bits.
         * (NaN's pop up when one does an invalid operation on a floating point value, such as dividing by zero, or taking the square root of a negative number.)
         */
        if (isExponentAllOneBits && mantissa.includes(1)) return NaN

        /**
         * Positive and Negative Infinity
         * Sign bit = 0 for positive infinity, 1 for negative infinity;
         * biased exponent = all 1 bits;
         * and the fraction = all 0 bits;
         */
        if (isExponentAllOneBits && isMantissaAllZeroBits) return sign * Infinity


        const exponent_result = exponent.reverse().reduce((prev, current, i) => {
            const exponent = i
            return prev + current * Math.pow(2, exponent)
        }, 0)

        const mantissa_result = mantissa.reduce((prev, current, i) => {
            const exponent = -(i + 1)
            return prev + current * Math.pow(2, exponent)
        }, 0) + 1

        return sign * (Math.pow(2, exponent_result - this.bias)) * mantissa_result
    }
}

const tests = [
    { my: new Float32('0', '00000000', '00000000000000000000000').getValue(), value: 0 },
    { my: new Float32('0', '01111011', '01011100001010001111011').getValue(), value: 0.085 },
    { my: new Float32('1', '10000001', '10110011001100110011010').getValue(), value: -6.800000190734863 },
    { my: new Float32('0', '11111111', '00000000000000000000000').getValue(), value: Infinity },
    { my: new Float32('1', '11111111', '00000000000000000000000').getValue(), value: -Infinity },
    { my: new Float32('1', '11111111', '01000000000000000001000').getValue(), value: NaN }
]
console.log(tests)
