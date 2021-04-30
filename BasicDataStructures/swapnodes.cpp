//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://leetcode.com/problems/swap-nodes-in-pairs/
//----------------------------------------------------------

/* 
    ==GOAL==
   Given a linked list, swap every two adjacent nodes and return its head.
   You may not modify the values in the list's nodes. Only nodes itself may be changed.

   Input: head = [1,2,3,4]
   Output: [2,1,4,3]




    Time Complexity:
        Insertion: Avg - 0(1) Worst - 0(1)
        Deletion: Avg - 0(1) Worst - 0(1)

    Space Complexity: Worst - O(n)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

//The structure for the nodes in the linklist
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} //Used for creation of the singly linked list

};

//Displays the linked list if it is not empty;
void displayList(ListNode* head){      
    std::cout << "[";
     while(head != NULL){
        std::cout<< head->val << ", ";
        head = head->next;           
    }
    std::cout << "\b\b]" << std::endl;     
}

/*
    Swap Pairs function
    If the head is empty or the next head is, return the head
    If not, then create a temp pointer and set it to the next head
    Swap the current head recursively
    Set the temp to the original head and return the temp
*/
ListNode* swapPairs(ListNode* head) {
    if (!head  || !head->next)
        return head;

    ListNode *temp = head->next;
      
    head->next = swapPairs(temp->next);
    temp->next = head;
      
    return temp;         
        
}


int main(){
    
    //Init head and pointer
    ListNode *head = new ListNode(1);
    ListNode *ptr = head;

    //Create list
    for (int i = 1; i < 4; i++){
        ptr->next = new ListNode(i+1);
        ptr = ptr->next;
    }

    //Test to see if list works
    std::cout << "List before swap: ";
    displayList(head);

    //Test to see if the swap function works
    std::cout << "Expected outcome: [2, 1, 4, 3]" << std::endl;
    std::cout << "Actual outcome: ";

    head = swapPairs(head);
    displayList(head);
    

   
    

    return 0;
}