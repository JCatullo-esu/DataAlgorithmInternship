//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/xor-se/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Array A is defined as follows
    A[0] = 0
    A[x] = A[x-1] ^ x for x > 0

    Given a left and rigth index l, r. Determine the XOR sum of a segment A as:
    A[l] ^ A[l+1]^ ... ^A[R-1]^A[r]

    Ex)
    Arr[0,1,3,0,4,1,7,0,8]
    l = 1, r = 4

    1 ^ 3 ^ - ^ 4 = 6

  Time Complexity:
         Avg - O(1) - Worst O(1)

    Space Complexity: O(1)

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the xorSequence function below.

/*
Knowing that every window of 4 elements in our sequence XORs to 2, 
we just need to identify if there are odd or even number of such windows. 
Even = 0, odd = 2. So, we are left with numbers that are out of these window sets, which can be 6 at max. 
This means that we XOR a maximum of 7 numbers, no matter what the L and R are.
*/

long xorval(long l,long r){
    return ((xorSequence(l-1))^xorSequence(r));
}

long xorSequence(long n) {
    long mod = n % 8;
    if(mod == 0 || mod == 1) return n;
    if(mod == 2 || mod == 3) return 2;
    if(mod == 4 || mod == 5) return n+2;
    if(mod == 6 || mod == 7) return 0;
    return 0;

}

//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string lr_temp;
        getline(cin, lr_temp);

        vector<string> lr = split_string(lr_temp);

        long l = stol(lr[0]);

        long r = stol(lr[1]);

        long result = xorSequence(l, r);

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
