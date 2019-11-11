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
        
So we will statr from side = 3 and if tetraminos doesn't fit in there, then increase the side.

## Creating decision list

Here our algorithm has discrepancies with the Knut algorithm. Knut suggests working mainly with columns. We decided that for our task it would be more convenient to work with rows.

Therefore, we are creating a slightly modified decision matrix. Add another vertical column with head nodes of the rows. In the head we keep the number of the row.

For the decision matrix, we used the following structure

    typedef struct			s_dest
    {
	    char		        name;
	    struct s_dest		*head;
	    struct s_dest		*left;
	    struct s_dest		*right;
	    struct s_dest		*up;
	    struct s_dest		*down;
	    int			        x;
	    int			        y;
	    int			        line;
    }				t_dest;
    
If we have the input, for example

	##..    ....    ....    ....
	.#..    ####    #...    ....
	.#..    ....    ###.    .##.
	....    ....    ....    ..##
	
The decision matrix (without first colomn) for the side of the square equal to 4, would be look like 
    
<img src="https://github.com/cghael/21_school_fillit/blob/master/dlist.jpg" width="300">

## Solution search

Now here begins the dancing links magic. How it works.

We launch a recursive function in which we indicate that by the solution for the first figure we select the first row with name = 'A'. And now we begin to cower rows.

First of all we cower all rows with name = 'A'. Because other decisions of this tetrimino we don't need. Our matrix will look like this

	AA...A...A......
	BBBB............
	....BBBB........
	........BBBB....
	............BBBB
	C...CCC.........
	.C...CCC........
	....C...CCC.....
	.....C...CCC....
	........C...CCC.
	.........C...CCC
	DD...DD.........
	.DD...DD........
	....DD...DD.....
	.....DD...DD....
	........DD...DD.
	.........DD...DD
	
Now we cover all the rows in which the letter is in the same position as the row that we chose for the solution. We start from the first column A and go down. When we done with this column matrix will be look like

	AA...A...A......
	BBBB............ <- cover
	....BBBB........
	........BBBB....
	............BBBB
	C...CCC......... <- cover
	.C...CCC........
	....C...CCC.....
	.....C...CCC....
	........C...CCC.
	.........C...CCC
	DD...DD......... <- cover
	.DD...DD........
	....DD...DD.....
	.....DD...DD....
	........DD...DD.
	.........DD...DD
	
	AA...A...A......
	....BBBB........
	........BBBB....
	............BBBB
	.C...CCC........
	....C...CCC.....
	.....C...CCC....
	........C...CCC.
	.........C...CCC
	.DD...DD........
	....DD...DD.....
	.....DD...DD....
	........DD...DD.
	.........DD...DD
	
Now we do it whith all other column with A

	AA...A...A......
	....BBBB........
	........BBBB....
	............BBBB
	.C...CCC........ <- cover
	....C...CCC.....
	.....C...CCC....
	........C...CCC.
	.........C...CCC
	.DD...DD........ <- cover
	....DD...DD.....
	.....DD...DD....
	........DD...DD.
	.........DD...DD
	
	AA...A...A......
	....BBBB........ <- cover
	........BBBB....
	............BBBB
	....C...CCC.....
	.....C...CCC.... <- cover
	........C...CCC.
	.........C...CCC
	....DD...DD..... <- cover
	.....DD...DD.... <- cover
	........DD...DD.
	.........DD...DD
	
	AA...A...A......
	........BBBB.... <- cover
	............BBBB
	....C...CCC..... <- cover
	........C...CCC.
	.........C...CCC <- cover
	........DD...DD. <- cover
	.........DD...DD <- cover
	
	AA...A...A......
	............BBBB
	........C...CCC.
	
Oops! We lost all rows with name = 'D'. Thats wrong. Our program should notice this and decide, that the row, that we chose this time as the solution is not suitable. We go back, uncover all covered rows and choose another row with the same name (in our case it's 'A').

And thats the main algo. We finished, when goal_row->name = '!', because this is the name of one single node - the root first node. And if we reach this node, we find the decision.

Decision of our example looks like

<img src="https://github.com/cghael/21_school_fillit/blob/master/dlist2.jpg" width="300">

That's all. Thanks!
