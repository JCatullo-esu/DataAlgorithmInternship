//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/construct-the-array/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Find the number of ways to construct an array such that consecutive posistions contain different values

    Specifcally, construct an array that has n elements, between 1 and k inclusive
    We also want the first and last elements of the array to be 1 and x

    Find it in mod 10^9 + 7

    Ex) n=4, k=3, x=2
    There are 3 ways to construct this array:
    [1,2,1,2]
    [1,2,3,2]
    [1,3,1,2]


    Time Complexity:
        Avg O(n) - Linear / single loop

    Space Complexity: 
        We are using a for loop so the avg and worst cases are going to be O(n)

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const long mod = pow(10,9) + 7; //Constraint for 10^9 + 7

// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    /* Two states the array can be in:
        1) Ends in X (a)
        2) Doesn't end in X (b)

        ai = bi-1` 
        bi = ai-1(k-1)"+bi-1(k-2)"'
      
        " - k-1 = can't be consecutive
        "' - k-2 = can't be x

    */
    vector<long long>a(n),b(n);
    
    //Use ? to determine if it ends x or doesnt end in x
    a[0] = x == 1 ? 1: 0; //Ends in X
    b[0] = x == 1 ? 0: 1; //Doesnt end in X

    //Starts at 1 because the array can not start at i-1 for a,b
    for (int i = 1; i < n; i++){
        a[i] = b[i - 1];
        b[i] = (a[i - 1] * (k-1)) + (b[i-1] * (k-2));

        a[i] %=  mod;
        b[i] %= mod;

    }

    return a[n-1];


}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

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
