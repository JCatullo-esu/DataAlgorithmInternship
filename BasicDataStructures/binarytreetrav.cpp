//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://leetcode.com/problems/binary-tree-level-order-traversal/
//----------------------------------------------------------

/* 
    ==GOAL==
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

   For example:
   Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

 [
  [3],
  [9,20],
  [15,7]
 ]


  Time Complexity:
        Insertion: Avg - O(log n)  Worst - O(n)
        Deletion: Avg - O(log n) Worst - O(n)

    Space Complexity: Worst - O(n)

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


#include <vector>
#include <iostream>
#include <queue>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

   
    //We initialize a queue in order to ultilzie the FIFO to make the BFS easier so we could organize the levels of the binary tree
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {

        std::vector<std::vector<int>> levels; //Stores the row on each level
        std::vector<int> level; //Stores the values of the BST
        std::queue<TreeNode*> children; //Queue to make BFS easier

        //If there is no root, return the vector
        if(!root)
            return levels;
       
        children.push(root);
        
        while(!children.empty()){
            int curr_size = children.size();
            
            //Itterate through the queue
            for(int i=0; i < curr_size; i++){
                TreeNode* front = children.front();
                children.pop();

                level.push_back(front->val);

                if(front->left) 
                    children.push(front->left);
                if(front->right) 
                    children.push(front->right);
            }
       
            //Push level to the vector and reset the levels
            levels.push_back(level);
            level.clear();
        }

        
        return levels;
    }    


    //To init the binary tree
    TreeNode *newTreeNode(int data){
        TreeNode *node = new TreeNode;
        
        node->val = data;
        node->left = node->right = NULL;
        

        return node;
    }


    //Used to add more nodes to the tree ((IN ORDER))
    TreeNode *insertTreeNode(TreeNode *node,int data){
        TreeNode *pointer;
        TreeNode *newNode;

        //If tree has nothing in it, init new tree
        if(node == NULL){
            newNode = newTreeNode(data);
            newNode -> parent = pointer;
            return newNode;
        }

        if(data <= node->val){
            pointer = node;
            node->left = insertTreeNode(node->left,data);

        }

        else{
            pointer = node;
            node->right = insertTreeNode(node->right,data);
        }

        return node;
    }

    //Print to see if the binary tree works
    void printTree(TreeNode *node){
        if (node == NULL)
            return;

        printTree(node->left);
        std::cout << node->val << " ";
        printTree(node->right);

    }




//Unordered BST, used to test out the leetcode problem
void testCase1(){
    std::cout << "==[**Test Case 1**]==" << std:: endl;
    TreeNode *root = newTreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    levelOrder(root);
    printTree(root);

}

//Ordered BST, used to test out insertTreeNode()
void testCase2(){
    std::cout << "==[**Test Case 2**]==" << std:: endl;
    TreeNode *root = newTreeNode(10);
    insertTreeNode(root,7);
    insertTreeNode(root,18);
    insertTreeNode(root,3);
    insertTreeNode(root,5);
    insertTreeNode(root,19);
    insertTreeNode(root,11);
    insertTreeNode(root,23);
    insertTreeNode(root,1);
    insertTreeNode(root,8);

    printTree(root);
    
}


int main(){

    testCase1();
    std::cout << std::endl << std::endl;
    testCase2();


 return 0;
}