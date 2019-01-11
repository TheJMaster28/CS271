// Jeffrey Lansford
// Lab 8
// 4/3/18
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct replyStr {
    int r1, r2;             
} replyRecord;

int min(int a, int b) {
    return (a < b) ? a : b;
}

replyRecord computeReply(int c1,int c2,int c3,int c4, 
                         int p1,int p2,int p3,int p4) { 

    replyRecord reply;
    int i, a1, a2, countC[6], countP[6];

    for (i=0; i<6; i++) countC[i] = 0;
    countC[c1]+=1; countC[c2]+=1; countC[c3]+=1; countC[c4]+=1;

    reply.r1 = (c1==p1) + (c2==p2) + (c3==p3) + (c4==p4);

    for (i=0; i<6; i++) countP[i]=0;
    countP[p1]+=1; countP[p2]+=1; countP[p3]+=1; countP[p4]+=1;

    reply.r2 = min(countC[0],countP[0]) +
               min(countC[1],countP[1]) +
               min(countC[2],countP[2]) +
               min(countC[3],countP[3]) +
               min(countC[4],countP[4]) +
               min(countC[5],countP[5]) - reply.r1;

    return reply;
}



int main(int argc, char *argv[])
{
   char line[128];
   int lastgs; 
   int c1, c2, c3, c4;
   int p1, p2, p3, p4;
   replyRecord reply;
   int numberOfTry = 0;
   FILE *logf;
   logf = fopen("codeMaker.log","w");

   srand(time(0));

   c1 = rand() % 6;
   c2 = rand() % 6;
   c3 = rand() % 6;
   c4 = rand() % 6;

   fprintf(logf, "the answers are:      %d %d %d %d\n",c1,c2,c3,c4);

   do {

      numberOfTry++;

      if (fgets(line,sizeof(line),stdin) < 0)
      {
          fprintf(logf,"End of input reached\n");
          fclose(logf);
          return;
      }

      if (sscanf(line,"%d%d%d%d", &p1, &p2, &p3, &p4) != 4)
      {
          fprintf(logf,"error: couldn't extract all 4 values!\n");
          return;
      }

      fprintf(logf, "read from controller: %d %d %d %d\n",p1,p2,p3,p4);
      
      lastgs = (reply.r1 * 10) + reply.r2;

      reply = computeReply(c1,c2,c3,c4,p1,p2,p3,p4);
      
       
      
      // logic for changing answer if last guess was (0,3), (3,0), or first try 
      if ( reply.r1 == 4 && reply.r2 == 0 ) {
          if ( (lastgs/10) ==0 && (lastgs%10) == 3) {
              while ( reply.r1 != 0 && reply.r2 != 3 ) {
              c1 = rand() % 6;
              c2 = rand() % 6;
              c3 = rand() % 6;
              c4 = rand() % 6;    
              reply = computeReply(c1,c2,c3,c4,p1,p2,p3,p4);
              fprintf(logf, "       the NEW answers are:      %d %d %d %d\n",c1,c2,c3,c4);
              }
          }
              
          if ( (lastgs/10) == 3 && (lastgs%10) == 0) {
              while ( reply.r1 != 3 && reply.r2 != 0 ) {
              c1 = rand() % 6;
              c2 = rand() % 6;
              c3 = rand() % 6;
              c4 = rand() % 6;    
              reply = computeReply(c1,c2,c3,c4,p1,p2,p3,p4);
              fprintf(logf, "       the NEW answers are:      %d %d %d %d\n",c1,c2,c3,c4);
              }
              
          }
          if ( numberOfTry <= 1 ) {
              c1 = rand() % 6;
              c2 = rand() % 6;
              c3 = rand() % 6;
              c4 = rand() % 6;    
              reply = computeReply(c1,c2,c3,c4,p1,p2,p3,p4);
              fprintf(logf, "       the NEW answers are:      %d %d %d %d\n",c1,c2,c3,c4);     
          }
      } 
      fprintf(logf, "write  to controller: %d %d\n", reply.r1, reply.r2);
      printf("%d %d\n", reply.r1, reply.r2);
      fflush(stdout);
   } while (reply.r1 < 4);

   fprintf(logf,"\nnumber of guesses:    %d\nDone!\n", numberOfTry);
   close(logf);

}

