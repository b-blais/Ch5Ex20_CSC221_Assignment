/*
Title: Chapter 5 Exercise 20 - Random Number Guessing Game
File Name : Ch5Ex20_CSC221_Assignment
Programmer : Brion Blais
Date : 11 / 2024
Requirements :
Random Number Guessing Game
Write a program that generates a random number and asks the user to guess what the number is.
If the user’s guess is higher than the random number, the program should display “Too high, try again.”
If the user’s guess is lower than the random number, the program should display “Too low, try again.”
The program should use a loop that repeats until the user correctly guesses the random number.
 */

#include <iostream>
#include <random>
using namespace std;

int randomNumber();
int validateNumber(int);

int main()
{
    int userGuess;
    int myRandomNumber = randomNumber();
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
    } 
    cout << "You have guessed the right number!";
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