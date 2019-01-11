// Jeffrey Lansford
// Lab 7
// 3/16/18
// task 2

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// self-referential structure                            
struct treeNode {                                           
   struct treeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   struct treeNode *rightPtr; // pointer to right subtree
}; 

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr &treePtr, int value);
void print(TreeNodePtr rootPtr);

// function main begins program execution
int main(void)
{ 
   TreeNodePtr rootPtr = NULL; // tree initially empty

   srand(time(NULL)); 
   cout << "The numbers being placed in the tree are:";

   // insert random values between 0 and 14 in the tree
   int i;
   for (i = 1; i <= 15; ++i) { 
      int item = rand() % 20;
      cout << "insert " << item << endl;
      insertNode(rootPtr, item);
      print(rootPtr);
   } 

} 

// insert node into tree
void insertNode(TreeNodePtr &treePtr, int value)
{ 
   // if tree is empty
   if (treePtr == NULL) {   
      treePtr = (TreeNodePtr)malloc(sizeof(TreeNode));

      // if memory was allocated, then assign data
      if (treePtr != NULL) { 
         treePtr->data = value;
         treePtr->leftPtr = NULL;
         treePtr->rightPtr = NULL;
      } 
      else {
         cout << value << " not inserted. No memory available.\n" << endl;
      } 
   } 
   else { // tree is not empty
      // data to insert is less than data in current node
      if (value < (treePtr)->data) {                   
         insertNode(treePtr->leftPtr, value);   
      }                                         

      // data to insert is greater than data in current node
      else if (value > treePtr->data) {                 
         insertNode(treePtr->rightPtr, value);     
      }                                        
      else { // duplicate data value ignored
         cout << " (duplicate) " << endl;
      } 
   } 
} 

void printHelper(TreeNodePtr treePtr, int depth)
{ 
   int i;
   if (treePtr == NULL) return;
   printHelper(treePtr->rightPtr, depth+1);         
   for (i=0; i<depth; i++) cout << "   " ;  
   cout << treePtr->data << endl;
   printHelper(treePtr->leftPtr,  depth+1);        
} 

void print(TreeNodePtr rootPtr) {
   cout << endl;
   printHelper( rootPtr, 0 ); 
   cout << endl;
}
