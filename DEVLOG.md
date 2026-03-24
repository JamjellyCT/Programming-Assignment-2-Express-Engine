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
