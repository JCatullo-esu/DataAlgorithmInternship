//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://www.hackerrank.com/challenges/strong-password/problem
//----------------------------------------------------------

/* 
    ==GOAL==
    A website needs a strong password in order for Louise to register.
    She typed a random string of lenght n in the password field but wasnt sure
    if it was strong.
    Given the string hse typed, can you find the minimium number of characrers
    she must add to make her password strong?


    A strong password satsifies the criteria:
    >Length is >= 6
    >It contains at least 1 digit
    >It contains at least one lowercase english char
    >It contains at least one uppercase english char
    >It contains at least one special character
        >>!@#$%^&*()-+


  Time Complexity:
         Avg - O(N) - Worst O(N)

    Space Complexity: O(N)

*/


#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
   // Return the minimum number of characters to make the password strong
    int count = 0;
    int flag[4] = {0,0,0,0}; //Flags are going to be used to indicate the requirements
  
    //A for loop that checks to see if the requirements for the password are met. If they arent, set the flag to 1.
    for (int i = 0; i < n; i++){
        if(password[i]>='a' && password[i]<='z')
            flag[0] = 1; //Lowercase flag
        else if(password[i]>='A' && password[i]<='Z')
            flag[1] = 1; //Uppercase flag
        else if(password[i]>='0' && password[i]<='9')
            flag[2] = 1; //Numerical flag
        else
            flag[3] = 1; //Special char flag
    }
    
    //For loop to sum up all the missing requirements
    for (int i = 0; i < 4;i++)
    {   
        if(flag[i] == 0)
            count+=1;
    }

    /*
        If the size of count and n combined is less than 6, return 6-n.
        If not, return the count.  
    */
    return n+count<6 ? 6-n : count;

}
//Hackerrank default main
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);
    cout << answer;

    fout << answer << "\n";

    fout.close();

    return 0;
}

