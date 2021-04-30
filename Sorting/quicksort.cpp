//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/quicksort2/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    Use quicksort - Picks elements as a piviot and partitions the given array around the picked pivot.

    The method quickSort takes in a parameter, ar, an unsorted array. Use the quicksort algorithim to sort the entire array.
    Use partition and merging in order to quicksort


  Time Complexity:
        Insertion: Avg - O(N Log(n))  Worst - O(n^2)

    Space Complexity: Worst - O(log(n))

*/


#include <bits/stdc++.h>
using namespace std;


void quickSort(vector <int> &arr) {

   if (arr.size() < 2)
        return;

   //Select first value as pivot point
   int pivot = arr.front();
   int j = 0;

   vector <int> leftarr;
   vector <int> rightarr;

   //Pivot already selected, start index at 1
   for(int i = 1; i < arr.size();i++){
       //If the values are less than or = to the pivot. push to the left array
       //Else, push the vals to the right
       if(arr[i] <= pivot)
         leftarr.push_back(arr[i]);

       else
         rightarr.push_back(arr[i]);  
   }


   quickSort(leftarr);
   quickSort(rightarr);

   
   //Copy left array back in the original array
   for (unsigned int i = 0; i < leftarr.size(); i++){
       arr[j++] = leftarr[i];
       cout << leftarr[i] << " ";
   }
   

   arr[j++] = pivot;
   cout << pivot << " ";
   

   for (unsigned int i = 0; i < rightarr.size(); i++){
       arr[j++] = rightarr[i];
       cout << rightarr[i] << " ";
    }

    cout << endl;

    


}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);
  


    return 0;
}
