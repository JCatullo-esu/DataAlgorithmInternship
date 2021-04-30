//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/camelcase/problem
//----------------------------------------------------------

/* 
    ==GOAL==
   There is a sequence of words in CamelCase as a string of letters s
   
   Camelcase has the following properties:
    >It is a conceatenation of one or more words consisting of english letters
    >All letters in the first word are lowercase
    >For each of the subsequent words, the ifrst letter is uppercase
    and the rest of the letters are lowercase

    Given s, determine the number of words in s

    ex)
    s = oneTwoThree

    output: 3 (one,Two,Three)

  Time Complexity:
         Avg - O(N) - Worst O(N)

    Space Complexity: O(N)

*/


#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int counter = 1;
    int size = s.length();

    /*From 65 to 90 are uppercase.
    Subtract the i value in the string by 90 and if its
    0 or a negative number, then it is a capital letter.
    If it is above 0 (which indicates its above 90 in ASCII)
    Do not increment counter. That will mean that s[i] is lowercase.
    */
   for (int i = 0; i < size; i++){
       if(s[i] - 90 <= 0)
         counter++;
   }

   return counter;

}

//Hackerrank default main code
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
