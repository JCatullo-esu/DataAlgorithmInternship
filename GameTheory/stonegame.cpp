//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/a-chessboard-game-1/forum
//----------------------------------------------------------

/* 
    ==GOAL==
    Two players P1 and P2 are playing a game starting with n number of stones.
    Player 1 always goes first and the two players move in alternating turns
    The game rules as follows:
        1) In a single movie, a player can remove either 2,3 or 5 stones from the game board
        2) If a player is unable to make a move, that player loses the game
    
    Ex) n = 4
    Player 1 removes 2 stones leaving 2
    Player 2 removes 2 stones. Player 2 wins

    Player 1 removes 3 stones leaving 1
    Player 2 is unable to make a move, player 1 wins.

  Time Complexity:
         Avg - O(1)  Worst - O(1)

    Space Complexity: O(1)

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfStones function below.
string gameOfStones(int n) {
    //Max cases are going to be 7 turns. We will find the remaidner of n divided by 7. If they end in 1 or a 0. Second player will win.
    if(n%7 == 1 || n%7 == 0)
        return "Second";
    //If there is a remainder >1, the first player will win.
    else
        return "First";
    
}

//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
