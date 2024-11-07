/*
Title: Chapter 5 Exercise 21 - Random Number Guessing Game with Counter
File Name : Ch5Ex20_CSC221_Assignment
Programmer : Brion Blais
Date : 11 / 2024
Requirements :
Random Number Guessing Game
Write a program that generates a random number and asks the user to guess what the number is.
If the user’s guess is higher than the random number, the program should display “Too high, try again.”
If the user’s guess is lower than the random number, the program should display “Too low, try again.”
The program should use a loop that repeats until the user correctly guesses the random number.
The branch adds in a counter and displays the number of guesses to the user.  I also added a function to have the user play against the computer.
 */

#include <iostream>
#include <random>
using namespace std;

int randomNumber();
int validateNumber(int);
int solveProblem(int);
int flagValidation(string);

int main()
{
    bool playing = true;
    
    while (playing) {
        string answer;
        int userGuess;
        int myRandomNumber = randomNumber();
        int numberGuesses = 0;
        cout << "Welcome to the guessing game!  I have chosen an integer between 1 and 1000, what is your guess? \t";
        cin >> userGuess;
        while (userGuess != myRandomNumber) {
            if (userGuess > myRandomNumber) {
                cout << "Too high, try again ... what is your next guess? \t";
                cin >> userGuess;
            }
            if (userGuess < myRandomNumber) {
                cout << "Too low, try again ... what is your next guess? \t";
                cin >> userGuess;
            }
            numberGuesses++;
        }
        cout << "It took you " << numberGuesses << " tries to guess the right number!\n";
        cout << "The computer just solved it in " << solveProblem(myRandomNumber) << " tries ... want to play again?";
        cin >> answer;
        playing = flagValidation(answer);
    }
    cout << "Okay, thanks for playing!";
    return 0;
}

int validateNumber(int inputNumber) {
    while ((inputNumber < 1 && inputNumber > 1000)) {
        cout << "Please enter a number between 1 and 1000 inclusive.\t";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> inputNumber;
    }
    return inputNumber;
}

int randomNumber() {
    random_device myengine;
    uniform_int_distribution<int> randomInt(1, 1000);
    return randomInt(myengine);
}

int solveProblem(int randomizedNumber) {
    int guess;
    int high = 1000, low = 1, count = 1;
    guess = (high + low) / 2;
    while (guess != randomizedNumber) {
        if (randomizedNumber > guess) {
            low = guess;
        }
        else {
            high = guess;
        }
        guess = (high + low) / 2;
        count++;
    }
    return count;
}

int flagValidation(string input) {
    int output = 2;
    do {
        if (input == "True" || input == "true" || input == "TRUE" ||
            input == "Yes" || input == "yes" || input == "YES") {
            output = 1;
        }
        else if (input == "False" || input == "false" || input == "FALSE" ||
            input == "No" || input == "no" || input == "NO") {
            output = 0;
        }
        else {
            cout << R"(You must anwser either "true / false or yes / no" to continue.)" << endl;
            cout << "Is the file you are trying to open in the same folder as this program?\t";
            cin >> input;
        }
    } while (output != 0 && output != 1);
    return output;
}