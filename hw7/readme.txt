First Part: HTree
Basically just convert the code we wrote last week into class-based. All the codes are explained in separate files. 

Compilation: g++ -g -std=c++2a htree.cc  test_htree.cc -o htree
Then enter ./htree in the terminal, the output I got is:

Get the key of the root: 126
Get the value of the root: 2
Get the key of the children to the left and then to the right: 6
Get the key of the children to the right and then to the right and then to the left: 8
Result for path to node 12 (equals to LL?): 1
Result for path to node 8 (equals to RRL?): 1
Result for path to node 9 (equals to LRL?): 1
Result for path to node 1231 (equals to nullptr?): 1

Then I used Valgrind to check if there is any memory mismanagement by typing: 

valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./htree 

in the terminal, and I got the following result:

==11569== Memcheck, a memory error detector
==11569== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11569== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==11569== Command: ./htree
==11569== 
Get the key of the root: 126
Get the value of the root: 2
Get the key of the children to the left and then to the right: 6
Get the key of the children to the right and then to the right and then to the left: 8
Result for path to node 12 (equals to LL?): 1
Result for path to node 8 (equals to RRL?): 1
Result for path to node 9 (equals to LRL?): 1
Result for path to node 1231 (equals to nullptr?): 1
==11569== 
==11569== FILE DESCRIPTORS: 3 open at exit.
==11569== Open file descriptor 2: /dev/pts/4
==11569==    <inherited from parent>
==11569== 
==11569== Open file descriptor 1: /dev/pts/4
==11569==    <inherited from parent>
==11569== 
==11569== Open file descriptor 0: /dev/pts/4
==11569==    <inherited from parent>
==11569== 
==11569== 
==11569== HEAP SUMMARY:
==11569==     in use at exit: 0 bytes in 0 blocks
==11569==   total heap usage: 55 allocs, 55 frees, 75,400 bytes allocated
==11569== 
==11569== All heap blocks were freed -- no leaks are possible
==11569== 
==11569== For lists of detected and suppressed errors, rerun with: -s
==11569== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Second Part: HForest
I used std::vector to store the trees with the name forest_vectore. 
size() method is just to return the size of the vector by using forest_vector.size(). 
add_tree(HTree::tree_ptr_t tree) is just pushing a shared_ptr of the tree given into the back of forest_vector.
In order to make the pop_tree() method in logarithmic time, I used make_heap with a comparsion to make forest_vector behaving a descending order of values. And then record the shared_pointer of the tree with lowest value in order to return it finally by using forest_vector.front() to access the first element. Then I used erase() method to delete the first element in the vector which is the shared_ptr of the tree with the lowest value. Noted that if there is no tree in the forest, pop_tree() should always return nullptr in this situation.

All the codes are explained in separate files.

Compilation: g++ -g -std=c++2a htree.cc hforest.cc test_hforest.cc -o hforest
Then enter ./hforest in the terminal, the output I got is:

original size of the forest: 0
size of the forest after adding 4 trees: 4
Output of every value of every tree in the forest: 213 6 1 23 
pop the tree with lowest value: 1
pop the tree with lowest value: 6
pop the tree with lowest value: 23
pop the tree with lowest value: 213
equal to nullptr? 1
size of the final forest: 0

Then I used Valgrind to check if there is any memory mismanagement by typing: 

valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./hforest

in the terminal, and I got the following result:

==11797== Memcheck, a memory error detector
==11797== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11797== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==11797== Command: ./hforest
==11797== 
original size of the forest: 0
size of the forest after adding 4 trees: 4
Output of every value of every tree in the forest: 213 6 1 23 
pop the tree with lowest value: 1
pop the tree with lowest value: 6
pop the tree with lowest value: 23
pop the tree with lowest value: 213
equal to nullptr? 1
size of the final forest: 0
==11797== 
==11797== FILE DESCRIPTORS: 3 open at exit.
==11797== Open file descriptor 2: /dev/pts/4
==11797==    <inherited from parent>
==11797== 
==11797== Open file descriptor 1: /dev/pts/4
==11797==    <inherited from parent>
==11797== 
==11797== Open file descriptor 0: /dev/pts/4
==11797==    <inherited from parent>
==11797== 
==11797== 
==11797== HEAP SUMMARY:
==11797==     in use at exit: 0 bytes in 0 blocks
==11797==   total heap usage: 13 allocs, 13 frees, 74,352 bytes allocated
==11797== 
==11797== All heap blocks were freed -- no leaks are possible
==11797== 
==11797== For lists of detected and suppressed errors, rerun with: -s
==11797== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)