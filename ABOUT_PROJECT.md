# Fillit
## Introduction

Program takes a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.

A ***Tetriminos*** is a 4-blocks geometric figure you probably already heard of, thanks to the popular game Tetris.

![Tetrimino](https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/All_5_free_tetrominoes.svg/2560px-All_5_free_tetrominoes.svg.png)

## Instuctions

* Project must be written in C and must respect the 42 School Norme coding standard.
* The allowed functions are : exit, open, close, write, read, malloc and free.
* You must compile your binary with the Wall, Wextra and Werror flags. Any other flag are forbidden , especially those for optimising purposes.
* Your project cannot have memory leaks.

## Entry

Every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino are separated by an newline each.
How tetriminos looks like:

    ....   ....  ####  ....  .##.  ....  .#..  ....  ....
    ..##   ....  ....  ....  ..##  .##.  ###.  ##..  .##. 
    ..#.   ..##  ....  ##..  ....  ##..  ....  #...  ..#.
    ..#.   ..##  ....  ##..  ....  ....  ....  #...  ..#.
    
I will not describe all the credentials of a valid file. You can see all the file’s validation checks in the file **ft_full_check_tetr.c**

## Goal

The goal of this project is to arrange every Tetriminos with each others in order to make the smallest possible square. But in some cases, this square should contains holes when some given pieces won’t fit in perfectly with others.

For example, if we have file with:

    #...    ....
    #...    ....
    #...    ..##
    #...    ..##
    
The uotput of the program must be:

    ABB.
    ABB.
    A...
    A...
    
All other outputs are not correct:

    A.BB   A...   ...A
    A.BB   ABB.   ...A
    A...   ABB.   BB.A
    A...   A...   BB.A
    
