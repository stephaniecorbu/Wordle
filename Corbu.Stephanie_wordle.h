#include <string>
using namespace std;
void drawBoard(string board[6][5]);
void fillBoard(string board[6][5]);
bool checkword(string board[6][5], string guess, string word,
                int amount_of_guesses);
string chooseword();
