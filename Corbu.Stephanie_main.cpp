//user enters any 5 letters and this program will indicate whether or not the letter is in the specific word. If the letter is green that means the letter is in the word in the correct spot. If the letter is yellow it means that the letter is in the word but not in the right spot. If the letter is white, it means the letter is not in the word. This porgram does not keep track of the amount of occurences of a letter in a word so if a letter is yellow or green that means the letter can be found more than once in the word.  


#include <iostream>
#include "wordle.h"
using namespace std;

int main() {
  string board[6][5] = {" "};
  string guess = "";
  int amount_of_guesses = 0;
  string word = chooseword();
  fillBoard(board);
  drawBoard(board);
  while (true) { // this is will loop forever until broken
    cout << "\nEnter a five letter word:";
    getline(cin, guess);
    // cout << guess; // whatever the user inputs will be put into a string called guess
    cout << "\033[2J\033[0;0H"; // this deletes the previous board
    if (guess.size() ==
        5) { // only valid inputs will be accepted the input must be 5 letters
      bool correctguess=checkword(board, guess, word, amount_of_guesses);
      drawBoard(board);
      amount_of_guesses++; // wordle only allows for fro 6 guesses
      if (correctguess) {
        cout << "\nYou've guessed the word!";
        break;
      } else {
        if (amount_of_guesses == 6) {
          cout << "\nThe word was:" << word;
          break;
        }
      }
    } else {
      cout << "\x1b[31mInput must be 5 letters\x1b[0m" << endl;
    }
  }
}
// check function.cpp for function definitions