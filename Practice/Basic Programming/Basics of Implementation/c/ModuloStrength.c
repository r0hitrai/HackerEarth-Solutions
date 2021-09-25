/* Alice is the teacher of a class having N students, where each
   student is having some personality value, given in the form of an
   array A. Here Ai denotes the personality value of ith student, where
   1 <= i <= N. Alice has special integer K with her. Student i is a
   friend of Student j, if and only if (A[i]%K) = (A[j]%k). Each
   student's strength is equal to the number of friends he/she has.
   Alice needs to calculate the sum of the strength of all the students
   in the class. Help Alice for the same.
   Note: This is a Code golf problem. You need to write code with
   minimum number of charaters.
*/
#include<stdio.h>
#define S(x) for(i=0;i<x;i++)
int main(){long a,b,c=0,d,i;scanf("%ld%ld",&a,&b);long e[b];S(b)e[i]=0;S(a){scanf("%ld",&d);e[d%b]++;}S(b)c+=e[i]*(e[i]-1);printf("%ld",c);}
