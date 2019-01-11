
/* NOTE: this is not the "smart" CodeBreakerSmart that I released */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct recordStr {
    int g1, g2, g3, g4;     // guesses 
    int r1, r2;             // replies from codeMaker
} record;

int     numberOfRecords = 0;
record  history[1296];

int min(int a, int b) {
    return (a < b) ? a : b;
}

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

int main(int argc, char *argv[])
{
   char line[128];

   int gs1, gs2, gs3, gs4;
   int p1, p2, p3, p4;
   int a1, a2, i;
   int countC[6], countP[6]; 
   FILE *logf;
   logf = fopen("codeBreaker.log","w");

   // srand(time(NULL));
   srand(3667);

   
   do {

      do {

         gs1=rand()%6; gs2=rand()%6; gs3=rand()%6; gs4=rand()%6;

      } while (!newAndConsistent(gs1,gs2,gs3,gs4));

      fprintf(logf, "write  to controller: %d %d %d %d\n", gs1, gs2, gs3, gs4);
      printf(                             "%d %d %d %d\n", gs1, gs2, gs3, gs4);

      fflush(stdout);

      if (fgets(line,sizeof(line),stdin) < 0) {
          fprintf(logf,"End of input reached\n");
          fclose(logf);
          return;
      }

      if (sscanf(line,"%d%d%d%d", &a1, &a2) != 2) {
          fprintf(logf,"error: couldn't extract all 2 values!\n");
          return;
      }

      fprintf(logf, "read from controller: %d %d\n",a1,a2);

      if (numberOfRecords > 1296) {
         fprintf(logf, "Error"); 
         close(logf); 
         exit(1);
      }

      history[numberOfRecords].g1 = gs1; 
      history[numberOfRecords].g2 = gs2; 
      history[numberOfRecords].g3 = gs3; 
      history[numberOfRecords].g4 = gs4; 
      history[numberOfRecords].r1 = a1;
      history[numberOfRecords].r2 = a2;
      numberOfRecords++;


   } while (a1 < 4);

   fprintf(logf,"Done!\n");
   close(logf);

}

