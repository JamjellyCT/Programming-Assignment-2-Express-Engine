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

