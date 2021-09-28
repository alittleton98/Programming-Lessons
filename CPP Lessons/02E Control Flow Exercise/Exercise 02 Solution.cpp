/*
This exercise will be a small dice throwing game to outline the principles of control flow, conditional response, and scope. The player will guess the total value of the dice thrown and the value of each die. The player will also be able to make predication guesses on the output before the dice are thrown.

Scoring Values:
- Total Value Correct: 5pts
- Value of Die Correct: 2.5pts (each)
- Player Predicted Max: 1pt
- Player Predicted Min: 1pt
- Die Values are Equal: 1pt

The maximum number of points awarded is 10 and 1pt scores are only awarded in the case that the player does not get the full 10 points from the Total Value or Die Value scores.
*/
#include <iostream>
#include <stdlib.h>


int main() {

	// Game Variables
	int PlayerTotalPoints;
	const int NumberOfRounds = 5;
	int CurrentRound = 0;

	// Scoring Values: Created as constants for value safety. Intuitively, the values shouldn't/won't change, but establishing a constant intentionally is often a good practice. Notice that the variables are "grouped" by value. This is because, even though there are 5 ways to earn points, there are only 3 numeric point values to be awarded. Limiting the number of created variables when possible saves memory usage. In a small example such as this, usage of memory and other resources isn't as critical, but it can become a problem in larger projects if the programmer is not in the habit of protecting resources. It is generally safer to assume resources are not available than to assume they are.

	const int PointAward_TotalValueCorrect = 5;
	const float PointAward_SingleDieCorrect = 2.5f;
	const int PointAward_RecoveryPointValue = 1;

	// User Input Variables: The variables taken from the user using cin
	int PlayerPredictedMax;
	int PlayerPredicatedMin;
	int DieValue1;
	int DieValue2;
	bool bDieValuesEqual;




	int FirstDieOutput;
	int SecondDieOutput;

	srand((unsigned)time(0));



	//conditionals 



	//loops

	return 0;
}