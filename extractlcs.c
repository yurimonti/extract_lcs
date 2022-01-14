//
// Created by Yuri Monti on 24/12/2021.
//

#include "extractlcs.h"
#include <stdlib.h>
#include "fileman.h"
#include "table.h"

/**
 * legge i bytes da due file e li confronta per calcolare una delle lcs possibili, scrivendola poi su un file di output
 * @param input1Name nome del primo file di input
 * @param input2Name nome del secondo file di input
 * @param outputName nome del file di output
 */
void extractlcs(char *input1Name,char *input2Name,char *outputName){
    t_table *table = NULL;
    table = allocTable();
    FILE *input1 = openInputFile(input1Name);
    FILE *input2 = openInputFile(input2Name);
    FILE *output = openOutputFile(outputName);
    table->nRow = fileSize(input1);
    table->nCol = fileSize(input2);
    table->row = (byte *)malloc(table->nRow);
    table->col = (byte *)malloc(table->nCol);
    allocMatrix(table);
    readBytesFromFile(table->row,input1,table->nRow);
    readBytesFromFile(table->col,input2,table->nCol);
    byte *outputBuffer = calculateLcs(table);
    writeBytesToFile(outputBuffer,output, getLcsLength(table));
    free(outputBuffer);
    closeFile(input1);
    closeFile(input2);
    closeFile(output);
    freeTable(table);
}
