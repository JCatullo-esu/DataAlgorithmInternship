//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/a-chessboard-game-1/forum
//----------------------------------------------------------

/* 
    ==GOAL==
   Two players are playing a game on 15x15 chessboard

   Rule:
   Game starts with a single coin located at some x,y cordinates. The coordinates of the upper left cell are (1,1)
   and the lower right cell are (15,15)

   In each move, a player must move the coin from cell (x,y) to the following locations
   1. (x-2,y+1)
   2. (x-2,y-1)
   3. (x+1,y-2)
   4. (x-1,y-2)

   Beginning with player 1, the players take alternate turns. The first player who is unable to make a move loses the game.

   Input contains an interger t, the number of test cases
   Each of the next t lines contain 2 space seperated integers x and y

   Ex) Input:
   3
   5 2
   5 3
   8 8

   Output:
   Second
   First
   First

  Time Complexity:
         Avg - O(1)  Worst - O(1)

    Space Complexity: O(1)

*/

#include <bits/stdc++.h>

using namespace std;


/*
For the particular game referenced here, the no-win states can be enumerated by starting at the north-west corner of the board and then working backwards.
(0,0) (0,1) (1,0) and (1,1) are all squares that force a loss on the next move. If you can manuever the knight to one of those squares you will win.
If not, your opponent will move to one of those squares and you will lose.
The rest of the logic flows from there.
*/
vector<string> split_string(string);

// Complete the chessboardGame function below.
string chessboardGame(int x, int y) {
   //Pattern for outcomes of the chessboard repeats every 4 rows. Mod 4 x and y to reduce redundancy 
   x = x % 4;
   y = y % 4;
 
  if(x == 0 || x == 3 || y == 0 || y == 3)
    return "First";

   return "Second";

}


//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        string result = chessboardGame(x, y);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
