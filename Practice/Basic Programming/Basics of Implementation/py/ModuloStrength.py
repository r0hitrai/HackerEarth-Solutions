# Alice is the teacher of a class having N students, where each
# student is having some personality value, given in the form of an
# array A. Here Ai denotes the personality value of ith student, where
# 1 <= i <= N. Alice has special integer K with her. Student i is a
# friend of Student j, if and only if (A[i]%K) = (A[j]%k). Each
# student's strength is equal to the number of friends he/she has.
# Alice needs to calculate the sum of the strength of all the students
# in the class. Help Alice for the same.
# Note: This is a Code golf problem. You need to write code with
# minimum number of charaters.
c=0
a=int(input().split()[1])
e=[0]*a
d=[int(i) for i in input().split()]
for i in d:
	e[i%a]+=1
for i in e:
	c+=i*(i-1)
print(c)
