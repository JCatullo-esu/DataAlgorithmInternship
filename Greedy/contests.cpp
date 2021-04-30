//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/luck-balance/problem
//----------------------------------------------------------

/* 
    ==GOAL==
   Lena is preparing for an important coding competition that is preceded by a number of sequential preliminary contests. 
   Initially, her luck balance is 0. She believes in "saving luck", and wants to check her theory. 
   Each contest is described by two integers, L[i] and T[i]

   L[i] is the luck assosciated with the contest
   T[i] indicates how important the contest is. 0 for unimportant and 1 for important

   If Lena loses no more than important contests, what is the maximum amount of luck she can have after competing in all the preliminary contests? 
   This value may be negative.


  EX)
    STDIN       Function
    -----       --------
    6 3         n = 6, k = 3
    5 1         contests = [[5, 1], [2, 1], [1, 1], [8, 1], [10, 0], [5, 0]]
    2 1
    1 1
    8 1
    10 0
    5 0

    Output: 29

  Time Complexity:
         Avg - O(N Log(n))  Worst - O(N Log(n)_

    Space Complexity: O(N)

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    int loss = 0;
    int sum = 0;
    
    //Sort the vectors from smallest to largest
    sort(contests.begin(),contests.end());
    
    //Traverse from top to bottom
    for (int i = contests.size()-1; i >= 0; i--){
        //If the contest is important and her luck is less than the # of important contests she could lose
        if((contests[i][1]==0)||((contests[i][1] == 1) && (loss < k))){
            //Add won contest to her sum (luck)
            sum+=contests[i][0];
            
            //If she loses the contest, increase her loss
            if (contests[i][1]!=0)
                loss++;
        }
        //Subtract the contest from her sum if the contest is unimportant
        else 
            sum-=contests[i][0];
    }
    
    return sum;
}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

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
