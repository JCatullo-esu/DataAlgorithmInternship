//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/countingsort1/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Given a list of integers, count and output the number of times
    each value appears as a list of space seperated integers

    ex)
    arr = [1,1,3,2,1]

    output:

    i arr[i]   result
    0	1	[0, 1, 0, 0]
    1	1	[0, 2, 0, 0]
    2	3	[0, 2, 0, 1]
    3	2	[0, 2, 1, 1]
    4	1	[0, 3, 1, 1]

  Time Complexity:
        Insertion: Avg - O(n+k)  Worst - O(n+k)

        Space Complexity: Worst - O(k)

*/

#include <bits/stdc++.h>

using namespace std;


vector<int> countingSort(vector<int> arr) {
 
    int size = arr.size();
    
    vector<int> countarr(100,0); //init array with 0's and max val , 0 < n < 100
    int countsize = countarr.size();
        
    for (int i = 0; i < size; i++)  
       countarr[arr[i]]++;
    

    for (int i = 0; i < size; i++)
        cout << countarr[i] << " ";
    
    
    return countarr;


}


int main(){

    vector<int> arr{1,1,3,2,1};
    countingSort(arr);
    cout << endl; 

    vector<int>arr2{63, 54, 17, 78, 43, 70, 32, 97, 16, 94, 74, 18, 60, 61, 35, 83, 13, 56, 75, 52, 70, 12, 24, 
    37, 17, 0, 16, 64, 34, 81, 82, 24, 69, 2, 30, 61, 83, 37, 97, 16, 70, 53, 0, 61, 12, 17, 97, 67, 33, 30, 49, 70, 
    11, 40, 67, 94, 84, 60, 35, 58, 19, 81, 16, 14, 68, 46, 42, 81, 75, 87, 13, 84, 33, 34, 14, 96, 7, 59, 17, 98, 
    79, 47, 71, 75, 8, 27, 73, 66, 64, 12, 29, 35, 80, 78, 80, 6, 5, 24, 49, 82};
    countingSort(arr2);

    return 0;


}

