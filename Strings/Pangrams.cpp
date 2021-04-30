//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/pangrams/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Given a sentence, determine whether it is a pangram in the
    english alphabet. Ignore case and return either pangram
    or not pangram 

  Time Complexity:
         Avg - O(N) - Worst O(N)

    Space Complexity: O(N)

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    char upper[26] = {0};
    char lower[26] = {0};
    for (int i = 0; i < s.length(); i++){
        //If the char is lowercase, add it to the array
        if (s[i] >= 'a' && s[i] <= 'z')
            lower[s[i]-'a'] = 1;
        //If the char is uppercase ,add it to the array
        else if (s[i] >= 'A' && s[i] <= 'Z')
            upper[s[i]-'A'] = 1;
    }

    for (int i = 0; i < 26; i++){
        if(!(upper[i] == 1 || lower[i] == 1))
            return "not pangram";
    }

    return "pangram";


}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

