//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/lonely-integer/problem
//----------------------------------------------------------

/* 
    ==GOAL==
  Given an array of integers, where all elements but one occur twice, find the unique element.

    Example
    The unique element is

    Function Description

    Complete the lonelyinteger function in the editor below.

    lonelyinteger has the following parameter(s):

        int a[n]: an array of integers

    Returns

        int: the element that occurs only once

    Input Format

    The first line contains a single integer,
    , the number of integers in the array.
    The second line contains space-separated integers that describe the values in .




    Time Complexity:
       This given algorithim has no insertion or deletion 
       Although for arrays in general: Insertion is: O(n) and deletion: O(n) on average cases
       Worst cases: O(n) for insertion and O(n) for deltion

    Space Complexity: Worst - O(n)

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the lonelyinteger function below.
int lonelyinteger(vector<int> a) {
    int lonely = 0;
    
    //XOR every bit in the vector
    for (int i = 0; i < a.size(); i++)
        lonely ^= a[i];
    
    return lonely;
}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = lonelyinteger(a);

    fout << result << "\n";

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