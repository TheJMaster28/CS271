// Jeffrey Lansford
// 3/4/18
// Lab5 Task 3 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure                            
typedef struct treeNode {   
    struct treeNode *subtree[2];
    int data; // node value      
     
                            
  
} TreeNode; 

//typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void print(TreeNodePtr p);


// function main begins program execution
int main(void)
{ 
    

   TreeNodePtr rootPtr = NULL; // tree initially empty
   
   srand(time(NULL));
 
   puts("The numbers being placed in the tree are:");

   // insert random values between 0 and 14 in the tree
   unsigned int i;
   
   for ( i = 1; i <= 10; ++i) { 
      
      int item = rand() % 15;
      printf("%3d", item);
      insertNode(&rootPtr, item);
      print(rootPtr);
      
   } 
  
 
} 

// ******insert node into tree************
void insertNode(TreeNodePtr *treePtr, int value)
{ 
    
    
    
    
  for( ; *treePtr ; ){
  for (; *treePtr && (*treePtr)->data < value; treePtr = &((*treePtr)->subtree[1])) ;
    
  for (; *treePtr && (*treePtr)->data > value; treePtr = &((*treePtr)->subtree[0])) ;
    
  if ( *treePtr && (*treePtr)->data == value){
      printf("%s", " dup");
      return;
  }// if
  }// for
  TreeNodePtr newPtr = malloc(sizeof(TreeNode));
  if (!newPtr) {printf("%c not inserted. No memory available.\n",value); return;}
  newPtr->data = value;
  newPtr->subtree[0] = *treePtr;
  newPtr->subtree[1] = *treePtr;
  *treePtr = newPtr;
  
}







/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
