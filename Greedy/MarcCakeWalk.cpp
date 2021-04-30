//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/marcs-cakewalk/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Marc loves cupcakes, but he also likes to stay fit. Each cupcake has a calorie count, and Marc can walk a distance to expend those calories. 

    If Marc has eaten j cupcakes so far, after eating a cupcake with c calories he must walk atleast (2^j x c) miles to maintain his weight.

    Ex)
    If Marc eats 3 cupcakes with the calorie counts: [5,10,7]

    The miles he would need to walk are (2^0 x 5) + (2^1 x 10) + (2^2 x 7) = 53.

    This is not the minimum. We need to track the orders of consuption. Our minimum is =

    (2^0 x 10) + (2^1 x 7) + (2^2 x 5) = 44

    Time Complexity:
        Since we are sorting a vector, the avg case is O(n Log(n))

    Space Complexity: 
        We are using a for loop so the avg and worst cases are going to be O(n)

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the marcsCakewalk function below.
long marcsCakewalk(vector<int> calorie) {
    long total = 0;
    
    //Sort the vector from greatest to least
    sort(calorie.begin(),calorie.end(),greater<int>());

    //Sum for loop
    for (int i = 0; i < calorie.size(); i++){
        total += pow(2,i) * calorie[i];
    }

    return total;
}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string calorie_temp_temp;
    getline(cin, calorie_temp_temp);

    vector<string> calorie_temp = split_string(calorie_temp_temp);

    vector<int> calorie(n);

    for (int i = 0; i < n; i++) {
        int calorie_item = stoi(calorie_temp[i]);

        calorie[i] = calorie_item;
    }

    long result = marcsCakewalk(calorie);

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
