#include <stdio.h>
#include "extractlcs.h"

void print_call_error(int args) {
    fprintf(stderr,"\n\nWrong number of parameters! Expected 3 are %d!\n",args);
    fprintf(stderr,"\nextractlcs <inputfile1> <inputfile2> <outputfile>\n\n");
}

int main(int argc, char** argv) {
    if(argc!=4){
        print_call_error(argc);
        return -1;
    }
    extractlcs(argv[1],argv[2],argv[3]);
    return 0;
}