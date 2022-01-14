//
// Created by Yuri Monti on 24/12/2021.
//

#ifndef EXTRACT_LCS_TABLE_H
#define EXTRACT_LCS_TABLE_H

typedef unsigned char byte;

typedef struct table_st {
    int *matrix;
    byte *row;
    int nRow;
    byte *col;
    int nCol;
}t_table;

t_table *allocTable();

t_table *allocMatrix(t_table *);

void freeTable(t_table *);

int getTablePosition(t_table *, int ,int );

int calculateLcsLength(t_table *);

int getLcsLength(t_table *);

byte *calculateLcs(t_table *);

#endif //EXTRACT_LCS_TABLE_H
