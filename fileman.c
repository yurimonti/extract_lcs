//
// Created by Yuri Monti on 24/12/2021.
//

#include "fileman.h"
#include <stdlib.h>

/**
 * controlla se il file è valido.
 * @param file da verificare
 * se il file non è valido allora da errore
 */
void isValidFile(const FILE *file){
    if (file == NULL) {
        perror("Error while opening input file.\n");
        exit(-1);
    }
}

/**
 * apre un file binario in lettura e ritorna il suo file descriptor
 * @param name (namepath) del file da aprire
 * @return file aperto
 */
FILE* openInputFile(char *name) {
    FILE* file = fopen(name,"rb");
    isValidFile(file);
    return file;
}

/**
 * apre un file binario in scrittura e ritorna il suo file descriptor
 * @param name (namepath) del file da aprire
 * @return file aperto
 */
FILE* openOutputFile(char *name) {
    FILE* file = fopen(name,"wb");
    isValidFile(file);
    return file;
}

/**
 * ritorna la lunghezza di un file
 * @param file su cui calcolare la lunghezza
 * @return lunghezza di un file
 */
long fileSize(FILE *file){
    isValidFile(file);
    fseek(file,0L,SEEK_END);
    long size = ftell(file);
    fseek(file,0L,SEEK_SET);
    return size;
}

/**
 * legge un numero di bytes da un file e li trasferisce su un buffer
 * @param buffer dei dati letti da un file
 * @param toRead file da cui leggere bytes
 * @param numOfBytes numeri di bytes da leggere dal file
 */
void readBytesFromFile(void *buffer,FILE *toRead,int numOfBytes){
    isValidFile(toRead);
    size_t read = fread(buffer,1,numOfBytes,toRead);
    if(read != numOfBytes) perror("Error while reading an input file.");
}

/**
 * scrive un numero di bytes da un buffer su un file
 * @param buffer contenenti i bytes da scrivere
 * @param outputFile file su cui scrivere i bytes
 * @param numOfBytes numero di bytes da scrivere sul file
 */
void writeBytesToFile(void *buffer,FILE *outputFile,int numOfBytes){
    isValidFile(outputFile);
    size_t written = fwrite(buffer,1, numOfBytes,outputFile);
    if (written != numOfBytes) perror("Error while reading output file.");
}

/**
 * chiude un file, se aperto
 * @param file da chiudere
 */
void closeFile(FILE *file){
    if (file != NULL) {
        fclose(file);
    }
}


