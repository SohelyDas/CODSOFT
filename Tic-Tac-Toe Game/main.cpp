#include <iostream>
#include <limits>
using namespace std;

char gameBoard[3][3];

void resetBoard() {
    char num = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gameBoard[i][j] = num++;
        }
    }
}

void showBoard() {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << " ";

        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == 'X')
                cout << "\033[1;36m " << gameBoard[i][j] << " \033[0m";
            else if (gameBoard[i][j] == 'O')
                cout << "\033[1;33m " << gameBoard[i][j] << " \033[0m";
            else
                cout << " " << gameBoard[i][j] << " ";

            if (j < 2)
                cout << "|";
        }

        cout << "\n";

        if (i < 2)
            cout << " ---+---+---\n";
    }

    cout << "\n";
}

bool winCheck(char player) {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == player &&
            gameBoard[i][1] == player &&
            gameBoard[i][2] == player)
            return true;

        if (gameBoard[0][i] == player &&
            gameBoard[1][i] == player &&
            gameBoard[2][i] == player)
            return true;
    }

    if (gameBoard[0][0] == player &&
        gameBoard[1][1] == player &&
        gameBoard[2][2] == player)
        return true;

    if (gameBoard[0][2] == player &&
        gameBoard[1][1] == player &&
        gameBoard[2][0] == player)
        return true;

    return false;
}

bool drawCheck() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O')
                return false;
        }
    }

    return true;
}

bool placeMove(char player, int pos) {
    if (pos < 1 || pos > 9)
        return false;

    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (gameBoard[row][col] == 'X' || gameBoard[row][col] == 'O')
        return false;

    gameBoard[row][col] = player;
    return true;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void title() {
    cout << "\033[2J\033[H";
    cout << "=====================\n";
    cout << "    TIC TAC TOE\n";
    cout << "=====================\n";
}

void showScore(int xScore, int oScore, int drawCount,
               string playerX, string playerO) {
    cout << "\n";
    cout << playerX << " (X): " << xScore << "   ";
    cout << playerO << " (O): " << oScore << "   ";
    cout << "Draws: " << drawCount << "\n";
}

int main() {
    string playerX, playerO;
    int xScore = 0, oScore = 0, drawCount = 0;

    title();

    cout << "Enter Player X name: ";
    cin >> playerX;

    cout << "Enter Player O name: ";
    cin >> playerO;

    char again = 'y';

    while (again == 'y' || again == 'Y') {

        resetBoard();

        char turn = 'X';
        bool finished = false;

        while (!finished) {

            title();
            showScore(xScore, oScore, drawCount, playerX, playerO);

            cout << "\nPositions:\n";
            cout << "1 2 3\n";
            cout << "4 5 6\n";
            cout << "7 8 9\n";

            showBoard();

            string currentPlayer =
                (turn == 'X') ? playerX : playerO;

            int move;

            cout << currentPlayer
                 << " (" << turn << ") choose a position: ";

            if (!(cin >> move)) {
                clearInput();
                cout << "Invalid input.\n";
                continue;
            }

            if (!placeMove(turn, move)) {
                cout << "Position already taken or invalid.\n";
                continue;
            }

            if (winCheck(turn)) {

                title();
                showScore(xScore, oScore, drawCount, playerX, playerO);
                showBoard();

                cout << currentPlayer
                     << " wins this round!\n";

                if (turn == 'X')
                    xScore++;
                else
                    oScore++;

                finished = true;
            }
            else if (drawCheck()) {

                title();
                showScore(xScore, oScore, drawCount, playerX, playerO);
                showBoard();

                cout << "Match Draw!\n";
                drawCount++;

                finished = true;
            }
            else {
                turn = (turn == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> again;
    }

    title();
    showScore(xScore, oScore, drawCount, playerX, playerO);

    cout << "\nFinal Result:\n";

    if (xScore > oScore)
        cout << playerX << " wins the series!\n";
    else if (oScore > xScore)
        cout << playerO << " wins the series!\n";
    else
        cout << "Series tied!\n";

    return 0;
}