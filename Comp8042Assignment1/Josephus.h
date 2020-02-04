#include <iostream>
#include "Vector.h"

using namespace std;

// The Josephus problem is the following game:
//  N people, numbered 1 to N, are sitting in a circle.
//  Starting at person 1, a hot potato is passed.
//  After M passes, the person holding the hot potato is eliminated,
//      the circle closes ranks, and the game continues
//      with the person who was sitting after the eliminated person
//      picking up the hot potato.
//  The last remaining person wins.
//  Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins.
//      If M = 1 and N = 5, the order of elimination is 2, 4, 1, 5.
// m is number of people
// n is number of passes before elimination
int Josephus(int m, int n)
{
	// Hint for making the algorithm efficient: think carefully how to determine next player to eliminate
	int winner = -1;
	Vector<int> people;
	for (int i = 1; i <= n; i++) {
		people.push_back(i);
	}

	auto currentPerson = 0;
	while (people.size() > 1) {
		for (int i = 0; i < m; i++) {
			currentPerson++;
			if (currentPerson == people.size() - 1) {
				currentPerson = 0;
			}
		}
		cout << people[currentPerson] << ", ";
		currentPerson = people.erase(currentPerson);
		if (currentPerson == people.size() - 1) {
			currentPerson = 0;
		}
	}
	cout << endl;
	winner = people[0];
	// Be sure to use cout to print out each player as they are eliminated
	return winner;
}
