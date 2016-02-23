/*
 * fgetline.h
 */

#ifndef FGETLINE_H
#define FGETLINE_H

#include <stdio.h>

#define MAXLINE 200
extern char buffer[MAXLINE+1];

char *fgetline(FILE *fp);

#endif FGETLINE_H
