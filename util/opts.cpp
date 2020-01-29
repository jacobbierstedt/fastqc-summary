#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>



int setopts(int argc, char **argv){
      int fflag = 0;
      int hflag =0;
      char *fvalue = NULL;
      int index;
      int c;


      opterr = 0;

      while((c= getopt(argc, argv, "hf:")) != -1)
        switch(c){
          case 'h':
            hflag = 1;
            break;
          case 'f':
            fflag = 1;
            fvalue = optarg;
            break;
          case '?':
            if(optopt== 'f' )
              fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
              fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
            fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);

            //return 1;
          default:
              exit (EXIT_FAILURE);
        }
        int flag = 0;
        if(hflag == 1){
          flag=1;
        } else if(hflag ==0 && fflag ==1){
          flag=2;
        }

    return flag;


}



void printusage(){

  printf("fastqc-summary\tBy: Jacob Bierstedt (jacob.bierstedt@und.edu)\n\n");
  printf("USAGE:\tfastqc-summary [options] <fastqc_directory>\n\n");
  printf("-f\t\tCreate .csv report from directory containing\n  \t\tunzipped fastqc supplementary directories\n");
  printf("-h\t\tPrint this useful and attractive help message\n\n");



}
