//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/icecream-parlor/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Johnny and Sunny like to pool their money and go to the ice cream parlor.
    Johnny never buys the same flavor that Sunny does.
    The only other rule they have is that they spend all their money

    Given a list of prices for the flavors of the ice cream, select the two 
    that will cost all of the money they have


    iceCreamParlor has the following params:
        m: int denoting the amount of money they have to spend
        cost: int array denoting the cost of each flavor of ice cream

    

  

  Time Complexity:
         Avg - O(N) - Worst O(N)

    Space Complexity: O(N)

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the icecreamParlor function below.
vector<int> icecreamParlor(int m, vector<int> arr) {
    vector <int> flavors; //To store the flavors that have been purchased

    int left = 0;
    int right = arr.size() - 1;
    bool flavornotfound = true;
    
    //Loop to itterate through the array
    while (flavornotfound){

        //If both indexes add up to the amount of money, return val to our array.
        if (arr[left] + arr[right] == m){
            //Add one to the indexes to accurately display location
            flavors.push_back(left+1); 
            flavors.push_back(right+1);
            flavornotfound = false; //Break out of loop
        }

        //If they dont add up, decrement the right value
        else{
            right = right - 1;
            //If the right gets low enough to = to the left val, reset right location
            if (left == right){
                left = left + 1; //Increment left, reset loop
                right = arr.size() - 1;
            }
        }

    }

    return flavors;
}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = icecreamParlor(m, arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
