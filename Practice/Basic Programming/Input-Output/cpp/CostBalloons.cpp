/* You are conducting a contest at your college. This contest consits
   of two problems and n participants. You know the problem that a
   candidate will solve during the contest.
   You provide a balloon to a participate after he or she solves a
   problem. There are only green and purple-colored balloons
   available in a market. Each problem must have a ballon
   associated with it as a prize for solving that specific problem. You
   can distribute balloons to each participant by performing the
   following operation:
   1. Use green-colored balloons for the first problem and purple-
      colored balloons for the second problem.
   2. Use purple-colored balloons for the first problem and green-
      colored balloons for the second problem.
   You are the given the cost of each balloon and problems that each
   participant solve. Your task is to print the minimum price that you
   have to pay while purchasing balloons.
*/
#include<iostream>
using namespace std;
int main() {
	int testCases, greenPrice, purplePrice, participants, problem1Win,  problem2Win, totalPrice;
	cin >> testCases;
	// running for each test case
	for (int i = 0; i < testCases; i++) {
		problem1Win = 0;
		problem2Win = 0;
		cin >> greenPrice;
		cin >> purplePrice;
		cin >> participants;
		int problem1[participants], problem2[participants];
		// inserting each participants wins in each problem
		for (int j = 0; j < participants; j++) {
			cin >> problem1[j];
			cin >> problem2[j];
		}
		// calculating total win for each problem
		for (int j = 0; j < participants; j++) {
			problem1Win += problem1[j];
			problem2Win += problem2[j];
		}
		// calculating minimum price for each problem
		if (greenPrice < purplePrice) {
			if (problem1Win > problem2Win)
				totalPrice = (greenPrice * problem1Win) + (purplePrice * problem2Win);
			else
				totalPrice = (greenPrice * problem2Win) + (purplePrice * problem1Win);
		}
		else {
			if (problem1Win > problem2Win)
				totalPrice = (purplePrice * problem1Win) + (greenPrice * problem2Win);
			else
				totalPrice = (purplePrice * problem2Win) + (greenPrice * problem1Win);
		}
		cout << totalPrice << "\n";
	}
	return 0;
}
