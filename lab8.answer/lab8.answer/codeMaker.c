

/* NOTE: this is not the "smart" CodeMakerSmart that I released */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ***BEGIN*** codes copied from codeBreaker.c 

typedef struct recordStr {
    int g1, g2, g3, g4;     // guesses 
    int r1, r2;             // replies from codeMaker
} record;

int     numberOfRecords = 0;
record  history[1296];

int Consistent(int c1,int c2,int c3,int c4, 
               int p1,int p2,int p3,int p4, int r1, int r2) { 

    int i, a1, a2, countC[6], countP[6];

    for (i=0; i<6; i++) countC[i] = 0;
    countC[c1]+=1; countC[c2]+=1; countC[c3]+=1; countC[c4]+=1;

    a1 = (c1==p1) + (c2==p2) + (c3==p3) + (c4==p4);

    for (i=0; i<6; i++) countP[i]=0;
    countP[p1]+=1; countP[p2]+=1; countP[p3]+=1; countP[p4]+=1;

    a2 = min(countC[0],countP[0]) +
         min(countC[1],countP[1]) +
         min(countC[2],countP[2]) +
         min(countC[3],countP[3]) +
         min(countC[4],countP[4]) +
         min(countC[5],countP[5]) - a1;

    return (a1==r1) && (a2==r2);
}

int newAndConsistent(int gs1, int gs2, int gs3, int gs4) {
    int i, g1, g2, g3, g4, r1, r2;
    for (i=0; i < numberOfRecords; i++) {
        g1 = history[i].g1;
        g2 = history[i].g2;
        g3 = history[i].g3;
        g4 = history[i].g4;
        r1 = history[i].r1;
        r2 = history[i].r2;
        if (g1==gs1 && g2==gs2 && g3==gs3 && g4==gs4) return 0;
        if (!Consistent(gs1,gs2,gs3,gs4,g1,g2,g3,g4,r1,r2)) return 0;
    }
    return 1;
}

int mindChangePossible() {
    int c1, c2, c3, c4;
    for (c1=0; c1<6; c1++) 
     for (c2=0; c2<6; c2++) 
      for (c3=0; c3<6; c3++) 
       for (c4=0; c4<6; c4++) 
           if (newAndConsistent(c1,c2,c3,c4)) return 1;
    return 0;
}

// ***END*** codes copied from codeBreak.c 






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
   int c1, c2, c3, c4;
   int p1, p2, p3, p4;
   replyRecord reply;
   int numberOfTry = 0;
   FILE *logf;
   logf = fopen("codeMaker.log","w");

   srand(time(NULL));

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

      reply = computeReply(c1,c2,c3,c4,p1,p2,p3,p4);



      
      // MIND CHANGE
      history[numberOfRecords].g1 = p1; 
      history[numberOfRecords].g2 = p2; 
      history[numberOfRecords].g3 = p3; 
      history[numberOfRecords].g4 = p4; 
      history[numberOfRecords].r1 = reply.r1;
      history[numberOfRecords].r2 = reply.r2;
      numberOfRecords++;
      if ((reply.r1 == 4) && mindChangePossible()) {
         do {
              c1=rand()%6; c2=rand()%6; c3=rand()%6; c4=rand()%6;
         } while (!newAndConsistent(c1,c2,c3,c4));
         reply = computeReply(c1,c2,c3,c4,p1,p2,p3,p4);
         history[numberOfRecords-1].r1 = reply.r1;
         history[numberOfRecords-1].r2 = reply.r2;
      }




      fprintf(logf, "write  to controller: %d %d\n", reply.r1, reply.r2);
      printf("%d %d\n", reply.r1, reply.r2);
      fflush(stdout);

   } while (reply.r1 < 4);

   fprintf(logf,"\nnumber of guesses:    %d\nDone!\n", numberOfTry);
   close(logf);

}

