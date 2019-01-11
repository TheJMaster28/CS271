// Alternate program to fig12_03.c (Inserting and deleting nodes in a list)

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
   if (!(*sPtr) || (*sPtr)->data >= value) 
   {
      ListNodePtr newPtr = malloc(sizeof(ListNode));
      if (!newPtr) {printf("%c not inserted. No memory available.\n",value); return;}
      newPtr->data = value;
      newPtr->nextPtr = *sPtr;
      *sPtr = newPtr;
      return;
   } 
   insert( &((*sPtr)->nextPtr), value );  // tail recursion
}

// delete a list element
char delete(ListNodePtr *sPtr, char value)
{
   if (!(*sPtr) || (*sPtr)->data > value) return '\0';
   if ((*sPtr)->data == value) 
   {
      ListNodePtr tempPtr = *sPtr;                              
      *sPtr = (*sPtr)->nextPtr;      
      free(tempPtr);                                           
      return value;
   }
   return delete( &((*sPtr)->nextPtr), value );  // tail recursion
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
