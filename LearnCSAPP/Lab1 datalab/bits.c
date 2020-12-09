/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // first: compare the 1 part
  int isOneSame = x & ~y;
  // then: compare the 0 part
  int isZeroSame = ~x & y;
  return ~(~isOneSame & ~isZeroSame);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int tmin = x + 1;
  int ntmin = (~tmin) + 1;
  return (!(tmin ^ ntmin)) & (!!tmin);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // first: construct the 0101...0101
  int cover = 0x01;
  cover = cover << 2 | cover;
  cover = cover << 4 | cover;
  cover = cover << 8 | cover;
  cover = cover << 16 | cover;
  // then: get it
  return !~(x | cover);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // for 0x30-0x37, meet 00110---
  int is07 = (x ^ 0x30) & (~8 + 1);
  // for 0x38-0x39, meet 0011100-
  int is89 = (x ^ 0x38) & (~2 + 1);;
  return !is07 + !is89;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // make x last bit 0 for all x != 0;
  int flag = (1 & !x) + ~1 + 1;  // 0x00 for x == 0, 0xFF for x != 0
  return (flag & y) + (~flag & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // y + -x >= 0
  // first: y + -x >=0, notice x == tmin
  int nx = ~x + 1;
  int sub = y + nx;
  int tmin = 1 << 31;
  // then the positive over and negate over
  int neg_over = !(nx & tmin & y); // 0 when is neg
  int normal = (!(nx ^ tmin)) | ((!(sub >> 31)) & neg_over);
  int posi_over = !((nx & tmin) | (y & tmin) | !(sub & tmin)); // 1 when is posi_over
  return normal + posi_over;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // find the way create all 1 and all 0
  int nx = ~x;
  nx = nx >> 1 & nx;
  nx = nx >> 2 & nx;
  nx = nx >> 4 & nx;
  nx = nx >> 8 & nx;
  nx = nx >> 16 & nx;
  return nx & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // ~negate_number return the same number
  int tmin = 1 << 31;
  int realx = (!(x & tmin) + ~1 + 1) ^ x; // x for x >= 0, ~x for x < 0, notice x == tmin
  // find the first 1
  int flag;
  int count = 0;  //31 when x == tmin, others 0
  flag = (!(realx >> 15) + ~1 + 1) & 16;  // 16 when first 1 at left 16 bits
  count = count + flag; realx = realx >> flag;
  flag = (!(realx >> 7) + ~1 + 1) & 8;  // 8 when first 1 at left 8 bits
  count = count + flag; realx = realx >> flag;
  flag = (!(realx >> 3) + ~1 + 1) & 4;  // 4 when first 1 at left 4 bits
  count = count + flag; realx = realx >> flag;
  flag = (!(realx >> 1) + ~1 + 1) & 2;  // 2 when first 1 at left 2 bits
  count = count + flag; realx = realx >> flag;
  flag = (!realx + ~1 + 1) & 1;  // 1 when first 1 at left 1 bits
  count = count + flag;
  return count + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // divide into 3 part: normal, denormal, NAN
  unsigned s = uf >> 31;
  unsigned exp = (uf & ((1 << 31) + (~1 + 1))) >> 23;
  unsigned frac = uf ^ (exp << 23) ^ (s << 31);
  // for NAN, return itself
  // printf("%x: %x, %x, %x\n", uf, s, exp, frac);
  if(!((~uf) & (0xFF << 23))){
    return uf;
  }
  // for denomal, frac << 1
  else if(!exp){
    return (frac << 1) + (uf & ((~1 + 1) << 23));
  }
  // for normal, exp++
  else{
    return uf + (1 << 23);
  }
  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned s = uf >> 31;
  unsigned exp = (uf & ((1 << 31) + (~1 + 1))) >> 23;
  int e = exp - 127;
  unsigned frac = uf ^ (exp << 23) ^ (s << 31);
  int temp;
  // find out of range, -2 ^ 31 << int << 2 ^ 31 - 1
  // find denormal number => return 0
  if(e <= 30){
    if(e < 0){
      return 0;
    }
    temp = (frac | (1 << 24));
    if(e - 23 >0){
      temp = temp << (e - 24);
    }else{
      temp = temp >> (24 - e);
    }
    if(s){
      temp = ~temp + 1;
    }
    return temp;
  }else{
    return 1 << 31;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // too large: x > 127
  if(x > 127){
    return 0xFF << 23;
  }
  // too small: x < -127 - 23
  else if(x < (-127 - 23)){
    return 0U;
  }
  // denormal:  x < -127 
  else if(x < -127){
    return 1U << (x + 127 + 23); 
  }
  else{
    return (x + 127) << 23;
  }
}
