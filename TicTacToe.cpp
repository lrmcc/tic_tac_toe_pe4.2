/*
Luke is Person 1
Joe is Person 2

(FINISHED) Decide who will be "Person 1" and who will be "Person 2"

(FINISHED) Set up a public Github repository.

(FINISHED) Person 1 - 
create a branch off of master and add a file "TicTacToe.cpp" 
with function CreateBoard which create an "empty" 3x3 matrix 
(you can decide what type you want this matrix contain, 
and if you'll represent it with a 2-dimensional array, vector, or something else). 
Create a main function in the same file that calls the CreateBoard function.
Commit this file and submit a pull request.

(FINISHED) Person 2 - 
review the changes made by Person 1, and merge those changes into master.
Once merged, create your own branch from the master for making changes.

(FINISHED) Steps 4 and 5 must be done simultaneously in your respective branches without consulting one another.
Person 2 writes a function to display the 3x3 matrix to the user with the name "DisplayBoard".
Person 1 also writes a function to display the 3x3 matrix to the user with the same name "DisplayBoard".
Person 2 will submit a Pull request. 
Person 1 will review and merge the changes into master.
Once merged, Person 1 will merge master into their branch. Work together to resolve the merge conflicts that arise.

(Currently->)The next step is to create functions "GetPlayerChoice", 
which should prompt the user for a location to play, then return that choice, 
and "PlaceMarker", which should take a location to play and a marker to place their 
and update the board accordingly. Each person should implement 1 of these functions 
and commit to their respective branches.

Once done, both of you will submit pull requests to master, 
which the other person will review and merge into master, 
then pull master into their own branch.

Work together to call your functions from the main file and simulate the game. 
You do not need to automatically check for a winner. 
One strategy you might take is to alternate players for 9 turns. 
You can assume that the players are "playing fair"—they are not trying to play in locations 
that have already been played in, etc.

Commit a README.md file with team member names, 
an indication of who was "person 1" and who was "person 2", 
a brief explanation of what your program does, and how to run the code.

Finally, run the program to play a sample game, 
copy the output and commit that output file named - "output.txt" into your repository.
*/

#include <iostream> 
#include <string>
#include <vector>
using namespace std; 

vector<vector<string> > CreateBoard() {
    int x = 3; 
    int y = 3; 
    vector<vector<string> > board( x , vector<string> (y, "  _  ")); 
    return board; 
}

void DisplayBoard(vector<vector<string> > tictactoe_board ) { 
    cout << "\n"<< endl;
    for (int i = 0; i < 3; i++) { 
            cout<< tictactoe_board[i][0];
            cout<< "|";
            cout<< tictactoe_board[i][1];
            cout<< "|";
            cout<< tictactoe_board[i][2] << "\n";
            if (i < 2) {
                cout<< " ____|_____|____\n";
            } else {
                cout<< "     |     |\n";
            }
    } 
    cout << "\n"<< endl;
}

string GetPlayerChoice(){

    string choice; 

    cout << "Type the number of the space you want to take your turn at followed by a capital X or O: " << endl; 

    cout << "1|2|3" <<endl;

    cout << "-----" <<endl;

    cout << "4|5|6" <<endl;

    cout << "-----" <<endl;

    cout << "7|8|9" <<endl;

    cout << "example turn valid entry could be \'5X\' or \'7O\'" <<endl;

    cin >> choice;

    cout << "Your entry was: " << choice <<endl; 

    return choice;

vector<vector<string> > PlaceMarker(string c, vector<vector<string> > tictactoe_board ) {
    vector<vector<string> > ttt_board = tictactoe_board;
    string::iterator si;
    si = c.begin();
    int position = int(*si) - 48;
    advance(si, 1);
    char mark = *si;
    cout << "position: " << position <<endl;
    position = position - 1;
    cout << "mark " << mark <<endl;
    int marknum = int(mark);
    string markstring;
    if (marknum == 88){
        markstring = "  X  ";
    } else if (marknum == 79){
        markstring = "  O  ";
    } else {
        cout << "invalid entry" <<endl;
        //GetPlayerChoice();
    } 

    if (position < 3){
        ttt_board.at(0).at(position) = markstring;
    } else if (position < 6){
        ttt_board.at(1).at(position-3) = markstring;
    } else if (position >= 6){
        ttt_board.at(2).at(position-6) = markstring;
    }
    return ttt_board;

}

int main() { 
    vector<vector<string> > Board = CreateBoard();
    DisplayBoard(Board);

    return 0; 
}













