Member:

Shweta Soparkar- ssopark1@binghamton.edu


How to Execute?

1> make
	will clean the existing output files

2> make all
	will execute the program 



An Optimal Binary Search Tree (BST), sometimes called a weight-balanced binary tree,is a binary search tree which provides the smallest possible search time (or expected search time) for a given sequence of accesses (or access probabilities). Used the dynamic programming technique for calculating the root node.Used an auxiliary array cost[n][n] to store the solutions of subproblems. cost[0][n-1] will hold the final result. The challenge in implementation was that all diagonal values must be filled first, then the values which lie on the line just above the diagonal. In other words, we must first fill all cost[i][i] values, then all cost[i][i+1] values, then all cost[i][i+2] value. The idea used in the implementation is same as Matrix Chain Multiplication problem.


This program will read from the command line the following two parameters: <input file name><output file name>.
The input file has the following structure:
Line 1 to n: <key><probability>

The output file:
The order of the lines in the output file is as in-order tree traversal. The first line is:
<key1> is the root of the tree.
Now the keys in the left subtree are typed in in-order traversal.  For example:
<key2> is the left child of the tree with parent <key1>
<key3> is the right child of the tree with parent <key2> …
Then the keys in the right subtree are printed.

Example 1
The keys are Don, Isabelle, Ralph, Wally, and their probability of occurrence is 3/8, 3/8, 1/8, 1/8.
The input file:
Line 1: Don 0.375
Line 2: Isabelle 0.375
Line 3: Ralph 0.125
Line 4: Wally 0.125
The output file:
Isabelle is the root of the tree
Don is the left child of Isabelle
Ralph is the right child of Isabelle
Wally is the right child of Ralph



Please run your code with the following input of 10 frequent stop words:
Line 1: the 0.29
Line 2: of 0.15
Line 3: and 0.12
Line 4: to 0.11
Line 5: a 0.09
Line 6: in 0.09
Line 7: that 0.04
Line 8: is 0.04
Line 9: was 0.04
Line 10: he 0.04
