#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "util/opts.h"
#include "util/summary.h"



int main(int argc, char **argv) {
    int flag = setopts(argc,argv);

    if(flag == 1 || argc != 3){
      printusage();
    }else if(flag ==2 && argc == 3){
      psum(argv[2]);
    } else { printusage();}
}
