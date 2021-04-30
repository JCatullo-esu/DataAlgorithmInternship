//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/coin-change/problem
//----------------------------------------------------------

/* 
    ==GOAL==
  Given an amount and the denominations of coins available, determine how many ways change can be made for amount. 
  There is a limitless supply of each coin type.

  The first input line contains two spaced ints n and m where:
  n is the amount to change and
  m is the number of coin types

   Ex)
   n = 3
   c = [8,3,1,2]

   There are 3 ways to make change for n = 3:
   {1,1,1}
   {1,2}
   and {3}

   Sample input: 4 3
   1 2 3

   Sample output: 4

     
  
  Time Complexity:
         Avg - O(2^m)  Worst - O(2^m)

    Space Complexity: O(mn)

*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

long getWays(int n, vector<long> c, int index) {
    vector <long> ways(n+1,0); //Init the # of possible combinations
    ways[0] = 1; //Start off all possible ways by including 1

    for (int i = 0; i < c.size(); i++){
        for (int j = 1; j < n+1; j++){ //Let the bounds by N + 1 for the number of coins avaible
            if (c[i] <= j) 
                ways[j] += ways[j-c[i]]; //Add J to the possible of ways the coins can be counted and remove c[i]
        }
    }

    return ways[n]; //The n of ways is the total number of combinations the coins can be collected

}


//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);
    
    int index = 0;

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c,index);

    fout << ways << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
