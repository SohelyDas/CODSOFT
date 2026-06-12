#include <iostream>
#include <limits>

using namespace std;

double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}

double mul(double x, double y) {
    return x * y;
}

double divi(double x, double y) {
    return x / y;
}

void showMenu() {
    cout << "\n===== Calculator =====\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice;
    double n1, n2, ans;

    cout << "Simple Calculator Program\n";

    while (true) {
        showMenu();

        if (!(cin >> choice)) {
            clearBuffer();
            cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice == 5) {
            cout << "Exiting Calculator...\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        cout << "Enter first number: ";
        if (!(cin >> n1)) {
            clearBuffer();
            cout << "Invalid input.\n";
            continue;
        }

        cout << "Enter second number: ";
        if (!(cin >> n2)) {
            clearBuffer();
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1:
                ans = add(n1, n2);
                cout << "Result = " << ans << endl;
                break;

            case 2:
                ans = sub(n1, n2);
                cout << "Result = " << ans << endl;
                break;

            case 3:
                ans = mul(n1, n2);
                cout << "Result = " << ans << endl;
                break;

            case 4:
                if (n2 == 0) {
                    cout << "Cannot divide by zero.\n";
                } else {
                    ans = divi(n1, n2);
                    cout << "Result = " << ans << endl;
                }
                break;
        }
    }

    return 0;
}