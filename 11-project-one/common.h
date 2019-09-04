#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Functions for validating inputs
int validate_inputs(char **argv);

//Functions for encrypting data
int encryption(char **argv);
int header_copy(FILE *fs, FILE *fd);
int passcode(FILE *fs, FILE *fd, int passcd);
int textfile_length(FILE *fs, FILE *fd, FILE *ft, int *text_length);
int textfile_copy(FILE *fs, FILE *fd, FILE *ft);
int rem_copy(FILE *fs, FILE *fd);

//Functions for decrypting data
int decryption(char **argv);
int decrypt_passcode(FILE *fd);
int decrypt_length(FILE *fd, int *length);
int decrypt_secret(FILE *fd, FILE *ft, int text_length);
#define ERROR -1
#define SUCCESS 1
#endif
