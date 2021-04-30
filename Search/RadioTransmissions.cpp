//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    The Mayor of the city wants to install radio transmitters on the roofs of the city's houses
    Each transmitter has a fixed range meaning it can transmit a signal to all houses within 
    that number of unit distance away.

    Given the range, determine the minimum number of transmitters so that every house
    is in range of atleast one transmitter. Each transmitter must be installed on top of an existing house

    Ex) n and k
    n is the number of houses 
    k is the transmission range

    Input: 5 1
    1 2 3 4 5

    Output: 2

    Time Complexity:
        Avg O(nLog(n)) - Sort algo

    Space Complexity: 
        O(n)

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the hackerlandRadioTransmitters function below.
int hackerlandRadioTransmitters(vector<int> x, int k) {
    
   sort(x.begin(),x.end()); //Sort array for greedy algo
   int size = x.size();
   int n = 0;
   int transmitter = 0;
   
   //Find furthest point to make calculation
   while (n < size){
       transmitter++; //There always has to be atleast one transmitter

       int location = x[n] + k; //Find the current posistion

       while(n < size && x[n] <= location) n++;
       cout << x[n] << " ";
       n--;
       

       location = x[n--] + k; //Set new location 
       while (n < size && x[n] <= location) n++;

   }

   return transmitter;

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

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

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
