#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    char choice = 'y';

    cout << "===== Number Guessing Game =====" << endl;

    while (choice == 'y' || choice == 'Y') {
        int number = rand() % 100 + 1;
        int guess;
        int tries = 0;

        cout << "\nGuess a number between 1 and 100." << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;

            if (guess < 1 || guess > 100) {
                cout << "Please enter a number from 1 to 100." << endl;
                continue;
            }

            tries++;

            if (guess < number) {
                cout << "Too low!" << endl;
            }
            else if (guess > number) {
                cout << "Too high!" << endl;
            }
            else {
                cout << "\nYou guessed it correctly!" << endl;
                cout << "Number: " << number << endl;
                cout << "Attempts: " << tries << endl;

                if (tries <= 5)
                    cout << "Excellent performance!" << endl;
                else if (tries <= 8)
                    cout << "Good job!" << endl;
                else
                    cout << "Keep practicing!" << endl;
            }

        } while (guess != number);

        cout << "\nPlay again? (y/n): ";
        cin >> choice;
    }

    cout << "\nThank you for playing!" << endl;

    return 0;
}