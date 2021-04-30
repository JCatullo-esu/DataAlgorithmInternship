//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/minimum-loss/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Lauren has a chart of distinct projected prices for a house over the next
    several years.
    She must buy the house in one year and sell it in another and she must
    do it at a loss. She wants to minimize her finanncial loss

    ex) prices = [20,15,8,2,12]
    return = 3

    Buy house at price[1] and sell it at price[4]
    15-12 = 3

    output: 3 (one,Two,Three)

  Time Complexity:
         Avg - O(nlogn) - Worst O(nlogn)

    Space Complexity: O(nlogn)

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumLoss function below.
int minimumLoss(vector<long> price) {
    //In order to sort without messing up the order, we put the prices in the pricemap
    map<long,int> pricemap;
    int size = price.size();
    
    //Allocate prices to the price map
    for (int i = 0; i < size; i++){
        pricemap[price[i]] = i;
    }
    
    sort(price.begin(),price.end());
    long minprice = LONG_MAX; //default value (will get overriden)
     //Use size-1 in order to prevent out of bounds error
     for(int i = 0; i < size-1; i++){
        long x = price[i+1] - price[i]; //Difference variable
        //If the value of the price is less than the price at [i], find the min price
            if (pricemap[price[i+1]] < pricemap[price[i]])
                minprice = min(minprice,x); //std::min
        
    }
    return minprice;
   
}

//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split_string(price_temp_temp);

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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
