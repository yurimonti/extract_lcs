//
// Created by Yuri Monti on 24/12/2021.
//

#ifndef EXTRACT_LCS_FILEMAN_H
#define EXTRACT_LCS_FILEMAN_H

#include <stdio.h>


void isValidFile(const FILE *);

FILE *openOutputFile(char *);

FILE* openInputFile(char *);

long fileSize(FILE *);

void readBytesFromFile(void *,FILE *,int );

void writeBytesToFile(void *,FILE *,int );

void closeFile(FILE *);

#endif //EXTRACT_LCS_FILEMAN_H
