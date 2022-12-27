#JMP-CALL-PO.  A really nice trick for writing x86 shellcode is the so called JMP/CALL/POP technique

Basically, we are trying to achieve two goals with it:

1-	Avoid any NULLs
2-	Avoid hardcoded addresses

we cannot use hardcoded addresses with shellcode. Hardcoded addresses reduce the likelihood of the shellcode working on different versions of Linux and in different vulnerable programs. You want your Linux shellcode to be as portable as possible, so you don’t have to rewrite it each time you want to use it. In order to get around this problem, we will use relative addressing. Relative addressing can be accomplished in many different ways

will use the most popular and classic method of relative addressing in shellcode

Relative addressing can be used in shellcode to specify the location of resources or destinations relative to the current position of the shellcode in memory. This can be useful in situations where the exact location of the shellcode is not known or may change, such as when the shellcode is injected into a running program or system.
For example, if the shellcode needs to call a function or access a specific memory location, it can use relative addressing to specify the location of the function or memory location relative to the current position of the shellcode. This allows the shellcode to access the function or memory location without needing to know the exact address of the function or location in memory.
Overall, relative addressing can be a useful technique in shellcode to make it more flexible and adaptable to changing environments, but it can also make it more difficult to detect and mitigate, as it can make it harder to identify the exact location and actions of the shellcode.

