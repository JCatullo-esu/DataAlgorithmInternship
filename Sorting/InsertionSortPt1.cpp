//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/insertionsort1/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Insert an element into a sorted list

    EX)
    Input: 5
    [2,4,6,8,3]

    Output:
    2 4 6 8 8 
    2 4 6 6 8 
    2 4 4 6 8 
    2 3 4 6 8 


  Time Complexity:
        Insertion: Avg - O(n^2)  Worst - O(n^2)

    Space Complexity: Worst - O(1)

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort1 function below.
void insertionSort1(int n, vector<int> arr) {

    //Descending down for loop
    for (int i = n-1; i < arr.size(); i--){ 
           int temp = arr[i];
           int j = i - 1;  

        //If the temp is less than the index before it, keep going down the list and replacing it
        while (j >= 0 && temp < arr[j]){

            arr[j+1] = arr[j];
            j--;     
            for (int k = 0; k < arr.size(); k++)
                cout << arr[k] << " ";
             cout << endl;
            
        }   
        arr[j+1] = temp;  
       
    }
    for (int k = 0; k < arr.size(); k++)
        cout << arr[k] << " ";
    cout << endl;
  
}

int main(){

    vector<int> arr = {2,4,6,8,3};

    insertionSort1(5,arr);



    return 0;

}