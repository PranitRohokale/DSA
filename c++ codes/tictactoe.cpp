#include <bits/stdc++.h>
using namespace std;

#define computer 'O'
#define human 'X'

class tictactoe
{
private:
    //variable
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    //methods
    void showInstruction();
    void showBoard();
    bool isBoardEmpty()
    {
        for (int i = 0; i < 9; i++)
            if (board[i] == ' ')
                return true;
        return false;
    }
    void playHuman();
    int playComputer();
    bool isWinner(char ch)
    {
        if ( //row
            (board[0] == board[1] && board[1] == board[2] && board[0] == ch) ||
            (board[3] == board[4] && board[4] == board[5] && board[3] == ch) ||
            (board[6] == board[7] && board[7] == board[8] && board[6] == ch) ||
            //coloum
            (board[0] == board[3] && board[3] == board[6] && board[0] == ch) ||
            (board[1] == board[4] && board[4] == board[7] && board[1] == ch) ||
            (board[2] == board[5] && board[5] == board[8] && board[2] == ch) ||
            //diagonal
            (board[0] == board[4] && board[4] == board[8] && board[0] == ch) ||
            (board[2] == board[4] && board[4] == board[6] && board[2] == ch))
            return 1;
        return 0;
    }
    bool isGameTie()
    {
        for (int i = 0; i < 9; i++)
            if (board[i] == ' ')
                return 0;
        return 1;
    }

public:
    tictactoe()
    {
        cout << "\t\t\t  Tic-Tac-Toe\n\n";
        cout << "Choose a cell numbered from 1 to 9 as below"
                " and play\n\n";
        showBoard();

        for (int i = 0; i < 9; i++)
            board[i] = ' ';
    }
    void playGame();
};
void tictactoe::showBoard()
{
    cout << "\t  " << board[0] << "  |  " << board[1] << " |  " << board[2] << endl;
    cout << "\t -------------" << endl;
    cout << "\t  " << board[3] << "  |  " << board[4] << " |  " << board[5] << endl;
    cout << "\t -------------" << endl;
    cout << "\t  " << board[6] << "  |  " << board[7] << " |  " << board[8] << endl;
}
void tictactoe::playHuman()
{
    while (1)
    {
        int choice;
        cout << "\nselect a position to place an \'X\' (1-9): ";
        cin >> choice;
        if (choice > 0 && choice <= 9 && board[choice - 1] == ' ')
        {
            board[choice - 1] = human;
            return;
        }
        else
            cout << "Try Agiain!!\n";
    }
}
int tictactoe::playComputer()
{
    vector<int> emptyMoves;
    for (int i = 0; i < 9; i++)
        if (board[i] == ' ')
            emptyMoves.push_back(i);

    vector<char> players = {'O', 'X'};

    for (auto p : players)
    {
        for (auto empty : emptyMoves)
        {
            board[empty] = p;
            if (isWinner(p))
            {
                return empty;
            }
            board[empty] = ' ';
        }
    }

    if (board[4] == ' ')
        return 4;

    set<int> corners = {0, 2, 6, 8};
    for (auto move : emptyMoves)
        if (corners.find(move) != corners.end())
            return move;

    set<int> sideMiddle = {3, 1, 5, 7};
    for (auto move : emptyMoves)
        if (sideMiddle.find(move) != sideMiddle.end())
            return move;
    return 0;
}
void tictactoe::playGame()
{

    while (isBoardEmpty())
    {
        if (!isWinner(human))
        {
            playHuman();
            showBoard();
        }
        else
        {
            cout << "\n O\'s won the game!";
            break;
        }
        if (!isWinner(computer))
        {
            int intelligentMove = playComputer();
            board[intelligentMove] = computer;
            cout << "Computer placed an \'O\' in position : " << intelligentMove + 1 << endl;
            showBoard();
            if (isWinner(computer)){
                cout << "\n\n O\'s won the game!";
                return;
            }
        }
        else
        {
            cout << "\n You won the game!";
            break;
        }
    }
    if (isGameTie())
        cout << "\nOhh...Game is Tie!!";
}

int main()
{
    tictactoe obj;
    obj.playGame();
    return 0;
}