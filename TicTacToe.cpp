/*

Luke McConnell is Person 1

Joe Falbo is Person 2

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

}

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

        GetPlayerChoice();

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

    vector<vector<string> > Board2 = PlaceMarker(GetPlayerChoice(), Board);

    DisplayBoard(Board2);

    vector<vector<string> > Board3 = PlaceMarker(GetPlayerChoice(), Board2);

    DisplayBoard(Board3);

    vector<vector<string> > Board4 = PlaceMarker(GetPlayerChoice(), Board3);

    DisplayBoard(Board4);

    vector<vector<string> > Board5 = PlaceMarker(GetPlayerChoice(), Board4);

    DisplayBoard(Board5);

    vector<vector<string> > Board6 = PlaceMarker(GetPlayerChoice(), Board5);

    DisplayBoard(Board6);

    vector<vector<string> > Board7 = PlaceMarker(GetPlayerChoice(), Board6);

    DisplayBoard(Board7);

    vector<vector<string> > Board8 = PlaceMarker(GetPlayerChoice(), Board7);

    DisplayBoard(Board8);

    vector<vector<string> > Board9 = PlaceMarker(GetPlayerChoice(), Board8);

    DisplayBoard(Board9);

    vector<vector<string> > Board10 = PlaceMarker(GetPlayerChoice(), Board9);

    DisplayBoard(Board10);

    return 0; 

}













