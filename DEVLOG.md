# Developer Log (DEVLOG.md)
## Expression Engine

---

### Session 1
**Date:** 2026-03-20
**Task worked on:**
Implemented ArrayStack<T>.
**Bugs or Issues**
No bugs or issues that I'm aware of.
**Tests**
Did not test implementation yet, that is for next session me. I am lazy right now.
**Fixed or Improved**
Improved ArrayStack<T>. It was blank before.


### Session 2
**Date:** 2026-03-21
**Task worked on:**
Tested ArrayStack<T>.
**Bugs or Issues**
No bugs or issues that I'm aware of. Pop, push, and top, all worked as intended.
**Tests**
Tested pushing values int stack. Tested popping values from vector. Tested stack underflow edge case in pop.
Tested finding top value of stack. Tested edge case of finding top of an empty stack.
Tested if finding size and if stack empty works.
**Fixed or Improved**
Proved that ArrayStack implementation works as intended.


### Session 3
**Date:** 2026-03-22
**Task worked on:**
Implemented Tokenizer
**Bugs or Issues**
Difficulty splitting multiple digit numbers. Example "33 * 4 + 2". The vector would've been 3 3 * 4 + 2 instead of 33 * 4 + 2.
**Tests**
Tested implementation of Tokenizer. Tokenizer correctly splits characters into valid tokens.
**Fixed or Improved**
Instead of using a for loop to create tokens, included sstream to read string and getline to split
the string for me. Way easier and less of a headache. This also fixed the issue of splitting multi digit numbers.


### Session 4
**Date:** 2026-03-23
**Task worked on:**
Implemented Precedence function
**Bugs or Issues**
Switch cases weren't working how I intended.
**Tests**
Implementation simple enough where it looks bout right. Will test when I know how the function is going to be used.
**Fixed or Improved**
Was blank before. Added coded yippe! Used if-else statements rather than switch cases.


### Session 5
**Date:** 2026-03-24
**Task worked on:**
Implemented isValidPostfix function. Very messy but what can you do when you're flying blind.
**Bugs or Issues**
Vector had two elements but my test printed empty list.
**Tests**
Tested if it correctly identified if a postfix was valid.
The first two elements are numbers
Last element is an operator
For every number there are number - 1 operators.
**Fixed or Improved**
The issue was the if statement that checked if the list was empty also checked if the size was less than or equal to 2.
Made sure the print statement included that it's empty or size is not big enough.

### Session 6
**Date:** 2026-03-25
**Task worked on:**
Implemented isValidInfix function. This fried my brain. Like am I doing this right :c. insert crying emoji.
**Bugs or Issues**
A lot of issues. Infix doesn't keep track of empty parenthesis, expressions like ( 3 + 5 ) * 4 
and (3 + 5) 4 are the same but I haven't added logic to account for this yet so it's falsely saying invalid.
Another issue for parenthesis balance is things like ( 3 + 4 ) ) ( * 2 is falsely said as valid.
**Tests**
Tested the simple 3 + 4 and stuff like (3 + 4) * 3, and they work as intended.
**Fixed or Improved**
I did not fix it yet. My brain is too fried to continue working so have some mercy please.

### Session 7
**Date:** 2026-03-26
**Task worked on:**
isValidInfix() function implementation.
**Bugs or Issues**
Still has issues of not recognizing (3 + 5)4 and (3 + 5)*4 are the same.
**Tests**
Tested bracket balancing and other parenthesis issues like )( passing as valid.
**Fixed or Improved**
Fixed issues such as )( and issues like (3 + ) + 4 passing as true when they are false.
Still needs improvements in other edgecases.



### Session 8
**Date:** 2026-03-26
**Task worked on:**
isValidInfix() function implementation. I took a lil break. This session the same day as 6.
**Bugs or Issues**
Regarding the isValidInfix function, none that I can think of or see.
**Tests**
Tested implied multiplication using parenthesis.
**Fixed or Improved**
Fixed issues like implied multiplication 3 ( 4 + 5 ) and (3 + 4) 5 all pass as intended.


### Session 9
**Date:** 2026-03-27
**Task worked on:**
Implemented infixToPostfix() function
**Bugs or Issues**
Operators weren't showing on postfix correctly. Result would look like 3 4 2 instead of 3 4 2 * +.
Closing parenthesis ), kept showing up within the postfix.
**Tests**
Tested infixToPostfix function. Now working as intended.
**Fixed or Improved**
Fixed issues such as operators not showing on postfix, as I forgot to pop them from the stack.
Fixed issue with parenthesis showing up in postfix, put tokens value instead of the value of top
into postfix.

### Session 10
**Date:** 2026-03-28
**Task worked on:**
Implemented evalPostfix() function
**Bugs or Issues**
Expressions such as 2 - 4 kept resulting in positive results such as 2.
Expressions such as 3 + e 2 were legal when they aren't valid.
**Tests**
Tested evalPostfix() function.
**Fixed or Improved**
Fixed expressions 3 + e 2 returning as a valid infix.
Fixed expressions such as 2 - 4 returning as postive by switching op2 - op1 to op1 - op2.
evalPostfix() function seems to be working as intended but more testing will be done.

### Session 11
**Date:** 2026-03-29
**Task worked on:**
Reimplemented tokenizer
**Bugs or Issues**
Tokenizer using ss stream would lump (3 + 4) as (3, +, and 4) as tokens 
when it should be (,3,+,4,). 
**Tests**
Tested new tokenizer to see if it still works as intended. 
It can now catch probles like (3+4) as a valud expression even without spaces.
**Fixed or Improved**
Improved tokenizer to catch expressions like (3+4) that aren't separated by spaces.
Though there is a problem I didn't notice with implicit multiplication and that is (3)(3) is not being
recognized properly.


### Session 12
**Date:** 2026-03-30
**Task worked on:**
Reimplemented infixToPostfix, makes it go through the original tokens to spot any implicit multiplication first.
**Bugs or Issues**
(3)(3) wasn't being recognized as implicit multiplication
**Tests**
Tested (3)(3) and other implicit multiplication expressions.
**Fixed or Improved**
New infixToPostfix now recognizes (3)(3) as 3 * 3. The brain no longer works right now that needs improvement but 
I think I am done?
