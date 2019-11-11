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

We decided to save tetrimino in the list:

    typedef struct			s_tet
    {
            char		        name;
    	int                     x[4];
    	int			y[4];
    	struct s_tet		*next;
    }				t_tet;
    
For each tetrimino we create new node. And for each tetrimino we adjust the coordinates so that the tetrimino itself appears to be in the upper left corner of the 4x4 square.

For example, if income tetrimino came in any of this ways

    ....    ####    ....    ....
    ....    ....    ####    ....
    ####    ....    ....    ....
    ....    ....    ....    ####
    
it coords will be saved as

        x {0, 1, 2, 3}
        y {0, 0, 0, 0}
        
## Side of the square

To speed up the search, we will not start with a 2x2 square. For example, we can say for sure that if we got 2 pieces, then they won’t fit into a 2x2 square. But maybe they get down to a 3x3 square? For example, in the case when input is

        .###    ....
        ...#    #...
        ....    ###.
        ....    ....
        
The solution will be

        AAA
        B.A
        BBB
        
So to find the smalest side to start the search from, we use area covered by tetramines

        side = √(N_tetrimino * 4) rounded up
        
In our example it will be

        side = √(2 * 4) = 2.8 = 3
        
So we will statr from side = 3 and if theraminos doesn't fit in there, then increase the side.

## Creating decision list

