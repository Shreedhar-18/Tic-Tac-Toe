#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

char current_marker;
int current_player;

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

void swap_player_and_marker() {
    if (current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if (current_player == 1) current_player = 2;
    else current_player = 1;
}

int main() {
    cout << "TIC TAC TOE GAME\n";
    cout << "Player 1 is X\nPlayer 2 is O\n\n";

    current_player = 1;
    current_marker = 'X';

    drawBoard();

    int moves = 0;
    while (true) {
        int slot;
        cout << "Player " << current_player << " (" << current_marker << "), enter your slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot. Try again.\n";
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken. Try again.\n";
            continue;
        }

        drawBoard();
        moves++;

        int win = winner();
        if (win != 0) {
            cout << "Player " << win << " wins! 🎉\n";
            break;
        }

        if (moves == 9) {
            cout << "It's a draw! 🤝\n";
            break;
        }

        swap_player_and_marker();
    }

    return 0;
}
