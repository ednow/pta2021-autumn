It is guaranteed that there is no overlap of the spaces occupied by these arrays.
+ 想说什么


2-6都是答案错误

7-1 Arrays and Linked Lists (20 分)
Let's design a data structure A that combines arrays and linked lists as the following:

At the very beginning, an integer array A
0
​
of length L
0
​
is initialized for the user. When the user tries to access the ith element A[i], if 0≤i<L
0
​
, then A[i] is just A
0
​
[i]. Now our system is supposed to return h
0
​
+i×sizeof(int) as the accessed address, where h
0
​
is the initial address of A
0
​
, and sizeof(int) is the size of the array element, which is simply int, taking 4 bytes.

In case there is an overflow of the user's access (that is, i≥L
0
​
), our system will declare another array A
1
​
of length L
1
​
. Now A[i] corresponds to A
1
​
[j] (It's your job to figure out the relationship between i and j). If 0≤j<L
1
​
, then h
1
​
+j×sizeof(int) is returned as the accessed address, where h
1
​
is the initial address of A
1
​
.

And if there is yet another overflow of the user's access to A
1
​
[j], our system will declare another array A
2
​
of length L
2
​
, and so on so forth.

Your job is to implement this data structure and to return the address of any access.

Input Specification:
Each input file contains one test case. For each case, the first line gives 2 positive integers N (≤10
4
) and K (≤10
3
) which are the number of arrays that can be used, and the number of user queries, respectively.

Then N lines follow, each gives 2 positive integers, which are the initial address (≤10
7
) and the length (≤100) of an array, respectively. The numbers are separated by spaces. It is guaranteed that there is no overlap of the spaces occupied by these arrays.

Finally, K indices of the elements queried by users are given in the last line. Each index is an integer in the range [0,2
20
].

Output Specification:
For each query, print in a line the accessed address. If the queried index exceeds the range of all the N arrays, output Illegal Access instead, and this query must NOT be processed.

Print in the last line the total number of arrays that have been declared for the whole process.

Sample Input:
6 7
2048 5
128 6
4016 10
1024 7
3072 12
9332 10
2 12 25 50 28 8 39
Sample Output:
2056
4020
1040
Illegal Access
3072
140
3116
5
###Hint:

A[2] is just A
0
​
[2], so the accessed address is 2048+2×4=2056.

In order to access A[12], declaring A
1
​
is not enough, we need A
2
​
with initial address h
2
​
=4016. Since A[12]=A
2
​
[1], the accessed address is 4016+1×4=4020.

In order to access A[25], we need A
3
​
with initial address h
3
​
=1024. Since A[25]=A
3
​
[4], the accessed address is 1024+4×4=1040.

The access of A[50] exceeds the maximum boundary of all the arrays, and hence an illegal access. There is no extra array declared.

In order to access A[28], we need A
4
​
with initial address h
4
​
=3072. Since A[28]=A
4
​
[0], the accessed address is just 3072.

It is clear to see that A[8]=A
1
​
[3] and hence the accessed address is 128+3×4=140; and A[39]=A
4
​
[11] so the accessed address is 3072+11×4=3116.

All together there are 5 arrays used for the above queries.
