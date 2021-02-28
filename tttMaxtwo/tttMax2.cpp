/* 
Max Cravetchi
Mr. Galbraith
C++ Programming

This program prints out a tic tac toe board.
It is a two player tic tac toe game.
First to get three in a row wins.
 */



#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void printBoard(char array[3][3]); //declares functions
char checkWin(char array[3][3]);
char checkTie(char array[3][3]);

char checkWin(char array[3][3]) { //checks if board entries are the same, for three in a row. returns a char.
  if(array[0][0] == array[0][1] && array[0][0] == array[0][2]){
    return 'W';
  }
  if(array[1][0] == array[1][1] && array[1][0] == array[1][2]){
    return 'W';
  }
  if(array[2][0] == array[2][1] && array[2][0] == array[2][2]){
    return 'W';
  }
  if(array[0][0] == array[1][0] && array[0][0] == array[2][0]){
    return 'W';
  }
  if(array[0][1] == array[1][1] && array[0][1] == array[2][1]){
    return 'W';
  }
  if(array[0][2] == array[1][2] && array[0][2] == array[2][2]){
    return 'W';
  }
  if(array[0][0] == array[1][1] && array[0][0] == array[2][2]){
    return 'W';
  }
  if(array[0][2] == array[1][1] && array[0][2] == array[2][0]){
    return 'W';
  }
}

char checkTie(char array[3][3]) { //checks for tie by checking if every entry in board is not the same as original 1 thru 9.
  if(array[0][0] != '1' &&
     array[0][1] != '2' &&
     array[0][2] != '3' &&
     array[1][0] != '4' &&
     array[1][1] != '5' &&
     array[1][2] != '6' &&
     array[2][0] != '7' &&
     array[2][1] != '8' &&
     array[2][2] != '9') {
  return 'T';
  }
}


void printBoard(char array[3][3]){ //prints the board foos
  cout<<endl;
  for(int x=0; x<3; ++x) {
    for(int y=0; y<3; ++y) {
      cout<<array[x][y]<<' ';
    }
    cout<<endl;
  }
}


int main(){
  int xWins;  //counts player x and o wins
  int oWins;

  bool replay = true;
  do{ //this do while loop clears everything besides xwins and owins if player wants to restart
    char board[3][3] = {'1','2','3','4','5','6','7','8','9'}; //og board
    printBoard(board);
    
    int player; //tracks the player - 0 is x, 1 is o.
    char position;
    bool fillOut = true; //fillout for until the board is filled out
    
    while (fillOut==true) {
      cout << "PUT IN A POSITION, 1 THRU 9! X IS FIRST! O IS NEXT! SO ON AND SO FORTH!" << endl;
      cin>>position;

      //checks if the pos inputted is a valid spot on board. if pos is repeated, the entry is not replaced. it will loop until a new pos is inputted, and the correct players sign (X, O) will go in the according pos.
      if(position == 49 | position == 50 | position == 51 | position == 52 | position == 53 | position == 54 | position == 55 | position == 56 | position == 57){ 
	for(int x=0; x<3; ++x){
	  for(int y=0; y<3; ++y) {
	    if(board[x][y]==position && player == 0){
	      board[x][y]='X'; //for loop goes thru board, and replaces the entry with X or O, if it is equal to the position char inputted
	      player = 1; //switches to O, loops thru again
	    } else if(board[x][y]==position && player == 1) {
	      board[x][y]='O';
	      player = 0;
	    }
	  }
	}
	printBoard(board);
	if(checkWin(board)=='W' && player == 1){ //if the checkwin returns the W char, for X
	  player = 0;
	  xWins++;
	  fillOut = false;
	  cout<<"X WINS! They have " << xWins << " wins so far. O has " << oWins << " in comparison" <<endl;
	  cout<<"Would you like to replay? 0 for no, 1 for yes" << endl;
	  cin >> replay;
	} else if (checkWin(board)=='W' && player == 0) { //if the checkwin returns the W char, for O
	  player=0;
	  oWins++;
	  fillOut = false;
	  cout<<"O WINS! They have " << oWins << " wins so far. X has " << xWins << " in comparison"<< endl;
	  cout<<"Would you like to replay? 0 for no, 1 for yes" << endl;
	  cin>>replay;
	} else if(checkTie(board)=='T'){ //if the checkwin returns the T Char for tie
	  player = 0;
	  fillOut = false;
	  cout<<"THE GAME IS A TIE! X and O have "<< xWins << " and " << oWins << " wins respectively"<< endl;
	  cout<<"Would you like to replay? 0 for no, 1 for yes"<<endl;
	  cin>>replay;
	}
      } else {
	cout << "PLEASE TYPE IN A VALID SPOT!" << endl;
      }
    }
  }while(replay==true);
  return 0;   
}
