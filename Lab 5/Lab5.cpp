/************
Anesu Mudzingwa
C++
David Busch
Lab 4: Temperature Output
Due Date: 14 October 2022
**************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

/**********
This code is seperated into 5 different functions
4 of them are in 1(GameLoop) that is further ran in the main function
***********/

void randomNoGenerator(int &randomNum);//This function's use is to make a random number between 1 and 100 for the user to try and guess
void switch_Win();//Fuction to provide the ouput if user wins the game using a switch statement
void switch_Lose();//Fuction to provide the ouput if user wins the game using a switch statement
void switch_Again();//Fuction to provide the ouput if user wins the game using a switch statement
void gameLoop(int &randomNum, string question);// Funtion to loop the game 20 times and again if the user chooses to(consists of two do while loops)




int main()
{
	int randomNum; 
	string question;

	gameLoop(randomNum, question);
	
	return 0;
}

void randomNoGenerator(int &randomNum)//random number generator for the game(0-100)
{
	
	srand((unsigned)time(0));
	randomNum = (rand()%100);
}

void gameLoop(int& randomNum, string question)
{
	int answer;
	int wins = 0;
	int losses = 0;

	do
	{
		
		int turns = 0;

		do
		{
			turns++;//incrementation of turns variable, used as the loop limit marker

			cout << "Please pick any number between 0 and 100: ";
			randomNoGenerator(randomNum);
			cin >> answer; //User input(attempt)

			//If statement to test if the user guesses the same number as the random number generator, if they did the loop ends and wins variable increments.
			if (answer == randomNum)
			{
				wins++;
				cout << "CPU's guess: " << randomNum << endl;
				cout << "Your guess: " << answer << endl;
				switch_Win();
				break;
			}

			//If statement to test if the user guessed the same number as the random number generator, if they did not the iteration will end and a new one will begin.
			if (!(answer == randomNum))
			{

				cout << "CPU's guess: " << randomNum << endl;
				cout << "Your guess: " << answer << endl;
				
				continue;
			}

		} while (turns < 20);//when the loop has been run 20 times, it will get out of the loop 

		losses++;
		
		switch_Lose();
		switch_Again(); 
		cin >> question;
	
		//If statement to get out of the loop if the user does not want to play again.
		if (!(question == "Y" || question == "y")) 
		{
			break;
		}

	} while (question == "Y" || question == "y");

	cout << "Thank you :) ";
	cout << "Game's won: " << wins << endl;
	cout << "Game's lost: " << losses << endl;


}

void switch_Win()
{
	//Random number generator for values 1-10 to choose between the different switch statement cases for different outputs to congratulate the user on winning
	srand((unsigned)time(0));
	int randomnumW = (rand() % 10 + 1);

	switch (randomnumW) 
	{
	case 1:
		cout << "Well done, you win!" << endl;
			break;

	case 2:
		cout << "Congrats, you got it!" << endl;
			break;

	case 3:
		cout << "Good guess!You win" << endl;
			break;

	case 4:
		cout << "You win!" << endl;
			break;

	case 5:
		cout << "On the money, good guess!" << endl;
			break;

	case 6:
		cout << "Spot on, you win!" << endl;
			break;

	case 7:
		cout << "Amazing guess!" << endl;
			break;

	case 8:
		cout << "Great Win" << endl;
			break;

	case 9:
		cout << "Perfect guess!" << endl;
			break;

	case 10:
		cout << "Fantastic guess!" << endl;
			break;
	}
}

void switch_Lose()
{
	//Random number generator for values 1-10 to choose between the different switch statement cases for different outputs to tell user they have lost.
	srand((unsigned)time(0));
	int randomnumL = (rand() % 10 + 1);

	switch (randomnumL) 
	{
		case 1:
			cout << "Unfortunately you are out of attempts." << endl;
			break;

		case 2:
			cout << "You lose." << endl;
			break;

		case 3:
			cout << "You have run out of attempts." << endl;
			break;

		case 4:
			cout << "No tries left, you failed to guess right." << endl;
			break;

		case 5:
			cout << "Round Lost. :(" << endl;
			break;

		case 6:
			cout << "Game Over." << endl;
			break;

		case 7:
			cout << "You lost the game." << endl;
			break;

		case 8:
			cout << "Oops those guesses were all incorrect." << endl;
			break;

		case 9:
			cout << "You do not have any attempts left." << endl;
			break;

		case 10:
			cout << "No more tries remaining you lose." << endl;
			break;
	}
}

void switch_Again() 
{

	//Random number generator for values 1-10 to choose between the different switch statement cases for different outputs to ask user to play again.
	srand((unsigned)time(0));
	int randomnumA = (rand() % 10 + 1);

	switch (randomnumA)
	{
		case 1:
			cout << "Again?(Y/N)" << endl;
			break;

		case 2:
			cout << "Cheer up ry again!(Y/N)" << endl;
			break;

		case 3:
			cout << "Unlucky, do you wish to play again?(Y/N)" << endl;
			break;

		case 4:
			cout << "C'mon, back on the horse and try another round?(Y/N)" << endl;
			break;

		case 5:
			cout << "Give it another try, do not give up. Replay?(Y/N)" << endl;
			break;

		case 6:
			cout << "Sorry all your guesses were incorrect, go again?.(Y/N)" << endl;
			break;

		case 7:
			cout << "Keep it going and give it another try.(Y/N)" << endl;
			break;

		case 8:
			cout << "Dial in and play again.(Y/N)" << endl;
			break;

		case 9:
			cout << "Do not give up, re-attempt!Play again?(Y/N)" << endl;
			break;

		case 10:
			cout << "Keep going!Again?(Y/N)" << endl;
			break;
	}
}