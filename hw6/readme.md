# Eriksen Liu
#tree.cc
1. For create_tree function, just to return a tree ptr which points to the new tree with the parameters in the function in the heap for future usage.

2. For the delete tree function, I wrote the function using the recursion. The base case is if the tree is nullptr, then we hit the stop for the recursion. The logics is to divide the tree into some subtree. Go to the left branch of the current branch, and if that one is nullptr, then go to the right, if it is still nullptr, then delete the current branch. Therefore, a branch is deleted. Then, with the same logic, with the subtree deleting, finally the whole tree will disappear.

3. Basically like the delete_tree function, we need to use a recursive function to solve as well. The simpliest case I can think of is when tree's key equals to the parameter key. When we meet the situation, return "" and wrap up the situation. Also, we need an indicator to tell the function that the tree is nullptr, so we use "-". Still, we need decompose the question into subtree to consider. From left to right, search every node in the tree like in delete_tree and add directions to the path.

4. By passing a tree pointer and a string into the function, I let N to be the lenght of the string to control the while loop length. For every character in the string, if it's not "L" or "R", return nullptr. If "R", then check if tree->right_ is nullptr or not; if it is, then return nullptr, if not, then tree = tree->right_. We do the same thing as "L", and finally we will get the node the string asked for, then return the pointer.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#test_tree.cc
1. I create a tree using create_tree which has the structure as,
/*
            126
           /   \
          /     \
        -5       12
        / \     /  \
      12   6   3    5
          /        /  \
         9        8    7
*/

2. I called path_to to test the function. I tested 8 to get RRL; 12 for LL (returned the lefe-most node); and 1123 which should return "-".

3. I tested node_at by passing some path as "LR" which should give as the tree pointer with key_ = 6 and so on.

4. Finally, delete the tree and free up the heap.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#actually run the code
1. since the code depends on each other, so I typed "g++ tree.cc test_tree.cc" in the terminal.

2. And it create a new file called a.out, then I typed "./a.out" in the terminal to see the result.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#result
I tested a.out from valgrind which gave me a message like below,

==2620== Memcheck, a memory error detector
==2620== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2620== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==2620== Command: ./a.out
==2620== 
RRL
LL
-
6
9
1
1
==2620== 
==2620== FILE DESCRIPTORS: 4 open at exit.
==2620== Open file descriptor 19: /dev/ptmx
==2620==    <inherited from parent>
==2620== 
==2620== Open file descriptor 2: /dev/pts/5
==2620==    <inherited from parent>
==2620== 
==2620== Open file descriptor 1: /dev/pts/5
==2620==    <inherited from parent>
==2620== 
==2620== Open file descriptor 0: /dev/pts/5
==2620==    <inherited from parent>
==2620== 
==2620== 
==2620== HEAP SUMMARY:
==2620==     in use at exit: 0 bytes in 0 blocks
==2620==   total heap usage: 12 allocs, 12 frees, 74,048 bytes allocated
==2620== 
==2620== All heap blocks were freed -- no leaks are possible
==2620== 
==2620== For lists of detected and suppressed errors, rerun with: -s
==2620== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)