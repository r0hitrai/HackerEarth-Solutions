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
import java.util.*;class M{public static void main(String x[]){Scanner s=new Scanner(System.in);long c=0;int a,b,d,i;a=s.nextInt();b=s.nextInt();long[] e=new long[b];for(i=0;i<a;i++){d=s.nextInt();e[d%b]++;}for(i=0;i<b;i++)c+=e[i]*(e[i]-1);System.out.print(c);}}
