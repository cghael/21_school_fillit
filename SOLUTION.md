# Solution

We decided to use the Knuth algorithm - Dancing Links or Algorithm X.
But since this algorithm is designed to solve the problems of full coverage, we had to change it a bit.

#### Why we decided to use this algo instead of simply brute force?

Well, because it's interesting, it's faster and we decided, that if we will do it, we will be gurus in understanding lists. 

### Decision steps

1. Validation input.
2. Save tetrimino from the file.
3. Find the side of the square with which we will begin the search.
4. Creating a decision matrix in the form of a four-way loop list.
5. Writing functions for covering and uncovering rows and storing a stack of these rows in memory.
6. Recursive solution search.

## Validation

Well, that was easy.

We decided to read from the file with BUFF_SIZE = 21, because the valid tetrimino takes 20 bytes (with '\n' at the end of each line) and separated from each other with a new line (1 byte).
So we read buf from file, check it and then we can save it. Buf by buf.

*PS. Remember about memory leaks, for example, if third read didn't pass the check.*

*PSS. And about usage.*

## Saving tetrimino
