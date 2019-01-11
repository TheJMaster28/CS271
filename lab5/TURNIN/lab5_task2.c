// Jeffrey Lansford
// 3/4/18
// Lab5 Task 2
/*
Test Cases for Task 2
1, 3, 2
a, c, b
1, a, 2, b, 3, c


*/
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {                                      
   char data;                
   struct listNode *nextPtr; 
} ListNode; 

typedef ListNode *ListNodePtr; 

unsigned int getChoice() {
   unsigned int choice;
   puts("Enter your choice:\n"
        "   1 to insert an element into the list.\n"
        "   2 to delete an element from the list.\n"
        "   3 to end.");
   printf("%s", "? ");
   scanf("%u", &choice);
   return choice;
}

// insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, char value)
{
   // recursive step for insert Task 2
   if ( *sPtr && (*sPtr)->data < value ) insert( &((*sPtr)->nextPtr), value);
   
   else {
   ListNodePtr newPtr = malloc(sizeof(ListNode));
   if (!newPtr) {printf("%c not inserted. No memory available.\n",value); return;}
   newPtr->data = value;
   newPtr->nextPtr = *sPtr;
   *sPtr = newPtr;

   }
}

// delete a list element
char delete(ListNodePtr *sPtr, char value)
{
   // recursive step for delete Task 2
   if ( *sPtr && (*sPtr)->data < value ) delete(sPtr = &((*sPtr)->nextPtr), value);
   
   else {
   if (!(*sPtr) || value != (*sPtr)->data) return '\0'; // 'value' not found in list
   ListNodePtr tempPtr = *sPtr;                         // hold onto node being removed
   *sPtr = (*sPtr)->nextPtr;                            // de-thread the node
   free(tempPtr);                                       // free the de-threaded node
   return value;

   }
}

void printList(ListNodePtr currentPtr)
{
   puts("The list is:");
   for (; currentPtr; currentPtr = currentPtr->nextPtr) printf("%c --> ", currentPtr->data);
   puts("NULL\n");
}

int main(void)
{ 
   ListNodePtr startPtr = NULL; 
   char item;

   while (1) 
      switch (getChoice()) {
         case 1:
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item); 
            printList(startPtr);
            break;
         case 2: // delete an element
            printf("%s", "Enter character to be deleted: ");
            scanf("\n%c", &item);
            if (!startPtr)                {puts("List is empty.\n");          break;}
            if (!delete(&startPtr, item)) {printf("%c not found.\n\n", item); break;} 
            printf("%c deleted.\n", item);
            printList(startPtr);
            break;
         case 3: 
            puts("End of run.");
            return;
         default:
            puts("Invalid choice.\n");
            break;
      } // end switch
} 
