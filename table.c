//
// Created by Yuri Monti on 24/12/2021.
//

#include "table.h"
#include <stdlib.h>
#include <stdio.h>

t_table *lcsLength(t_table *,int,int);

/**
 * calcola la lunghezza della lcs della posione corrente della matrice
 * se il byte della riga all indice row e quello dell indice col della colonna
 * sono uguali, allora si somma 1 al numero contenente nella posizione [row-1,col-1]
 * e lo si inserisce nella posizione corrente.
 * altrimenti si ritorna il max del lcs tra la posizione [row,col-1] e [row-1,col]
 * @param table contenente la matrice
 * @param row indice della riga
 * @param col indice della colonna
 * @return table con posizione corrente della matrice aggiornata
 */
t_table *lcsLength(t_table *table,int row,int col){
    byte byteOfRow = table->row[row-1];
    byte byteOfCol = table->col[col-1];
    int upper = table->matrix[getTablePosition(table,row-1,col)];
    int left = table->matrix[getTablePosition(table,row,col-1)];
    if(byteOfRow==byteOfCol) table->matrix[getTablePosition(table,row,col)] = table->
            matrix[getTablePosition(table,row-1,col-1)]+1;
    else{
        if(upper>=left) table->matrix[getTablePosition(table,row,col)] = upper;
        else table->matrix[getTablePosition(table,row,col)] = left;
    }
    return table;
}

/**
 * restituisce la lunghezza della LCS
 * @param table
 * @return lunghezza della LCS
 */
int getLcsLength(t_table *table){
    return table->matrix[(table->nRow +1)*(table->nCol +1)-1];
}

/**
 * calcola la lunghezza della lcs per ogni posizione della matrice
 * @param table contenente la matrice da riempire
 * @return il numero della lcs massima.
 */
int calculateLcsLength(t_table *table){
    if(table == NULL){
        perror("this table not exists");
        exit(-1);
    }
    if(table->nRow!=0 && table->nCol!=0){
        for (int i = 1; i <= table->nRow; i++) {
            for (int j = 1; j <= table->nCol; j++) {
                table = lcsLength(table,i,j);
            }
        }
    }
    return table->matrix[(table->nRow+1)*(table->nCol+1)-1];
}

/**
 * calcola una delle LCS tra due flussi di bytes
 * @param table
 * @return puntatore a byte del primo byte della LCS
 */
byte *calculateLcs(t_table *table){
    int lcsSize = calculateLcsLength(table);
    byte *result = (byte *)malloc(lcsSize);
    int i = table->nRow;
    int j = table->nCol;
    while (i>0 && j>0 &&lcsSize>0){
        int left = table->matrix[getTablePosition(table,i,j-1)];
        int upper = table->matrix[getTablePosition(table,i-1,j)];
        int current = table->matrix[getTablePosition(table,i,j)];
        if(current > upper && current > left) {
            result[lcsSize-1] = table->row[i-1];
            lcsSize--;i--; j--;
        }
        else {
            if(upper>=left)i--;
            else j--;
        }
    }
    return result;
}

/**
 * alloca memoria per una table vuota
 * @return
 */
t_table *allocTable(){
    t_table *table = (t_table*)malloc(sizeof(t_table));
    table->matrix = NULL;
    table->row = NULL;
    table->nRow = 0;
    table->col = NULL;
    table->nCol = 0;
    return table;
}

/**
 * alloca memoria per la matrice della table
 * @param table contenente la matrice da allocare
 * @return
 */
t_table *allocMatrix(t_table *table){
    if(table->matrix!=NULL) free(table->matrix);
    table->matrix = (int *) malloc((table->nRow+1)*(table->nCol+1)*sizeof(int));
    for (int i = 0; i <= table->nCol; i++) {
        table->matrix[i] = 0;
    }
    for (int i = 1; i <= table->nRow; i++) {
        table->matrix[getTablePosition(table,i,0)]=0;
    }
    return table;
}

/**
 * resistuisce la posizione della matrice secondo gli indici
 * @param table
 * @param row indice per le righe
 * @param col indice per le colonne
 * @return posizione nella matrice
 */
int getTablePosition(t_table *table,int row,int col){
    return (row * (table->nCol+1))+col;
}

/**
 * libera memoria allocata da una table
 * @param table da liberare in memoria
 */
void freeTable(t_table *table){
    if(table!=NULL){
        if(table->matrix!=NULL){
            free(table->matrix);
            table->matrix = NULL;
        }
        if(table->row!=NULL){
            free(table->row);
            table->row = NULL;
            table->nRow = 0;
        }
        if(table->col!=NULL){
            free(table->col);
            table->col = NULL;
            table->nCol = 0;
        }
        free(table);
    }
}
