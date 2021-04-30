//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/counter-game/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Louise and Richard have developed a numbers game.
    They pick a number and check to see if it is a power of 2. 
    If it is, they divide it by 2. If not, they reduce it by the next lower number which is a power of 2. 
    Whoever reduces the number to 1 wins the game. Louise always starts.

    EX) Start with n=132
    132 is NOT a power of 2, reduce it to 128 which IS a power of 2
    Subtract 132 by 128 and get 4. Give 4 to Richard.
    4 IS a power of 2, divide it by 2, get 2. Give 2 to Louise.
    Louise divdes 2 by itself since 2 is divisible by 2, Louise gets 1.
    Louise wins the game
  

  Time Complexity:
         Avg - O(N Log(n))  Worst - O(log(N))

    Space Complexity: O(log(N))

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.
string counterGame(long n) {
    int turn = 0;
    string winner = "";
    
    //If N is divisble by 2, divide it by 2 and swap turns
    while(n > 0 && n%2==0){
        n = n/2;
        turn++;
    }
    
    //If N is not divisble by 2, decrease it by the power of n^2.
    while(n>0){
        if (n%2==1) //If it is not divisble by 2, increase turn
            turn++;
        n >>= 1; //Lower n by n^2
    }
    
    //Declare winners based on turn
    if (turn%2==0)
        winner = "Louise";
    else {
        winner = "Richard";
    }
  
    return(winner);
}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
