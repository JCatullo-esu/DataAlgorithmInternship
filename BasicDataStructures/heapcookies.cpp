//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/jesse-and-cookies/problem
//----------------------------------------------------------

/* 
    ==GOAL==
   Jesse is baking cookies. 
   He wants all of the sweetness of all his cookies to be greater than the value K.
   To do this, Jesse repeatedly mixes two cookies with the least sweetness.
   He creates a special combined cookie with:
    sweetness = (1 x Least sweet cookie + 2 x 2nd least sweet cookie)
   He repeats this procedure until all cookies have a sweetness > K
   

   Ex) 
   Sample input: 6 7
    1 2 3 9 10 12

   Sample output: 2
     
  
  Time Complexity:
         Avg - O(N Log(n))  Worst - O(N Log(n))

    Space Complexity: O(1)

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) {
    int sweet=0;
    priority_queue<int,vector<int>,greater<int>> heap;

    //Initialize the priority queue (heap)
    for (int i = 0; i < A.size(); i++)
        heap.push(A[i]);

    //Check to see if the heaps do not meet the min requirement of sweetness
    while (heap.top() < k){
        int temp = heap.top();
        heap.pop();

        //Output -1 if the heap is empty (specificed in the problem)
        if(heap.empty())
            return -1;

        int temp2 = heap.top();
        heap.pop();

        //Make calculations for sweetness
        heap.push(temp+2*temp2);
        sweet++;
        
    }

    return sweet;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

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
