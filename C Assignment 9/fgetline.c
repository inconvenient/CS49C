/*
 * fgetline.c
 */

#include <stdio.h>
#include <string.h>

#include "fgetline.h"

char buffer[MAXLINE+1];

char *fgetline(FILE *fp)
{
	// Get a line, return it without the newline char

	// Read a line, possibly with a new line
	if (!fgets(buffer, MAXLINE-1, fp))
	{
		return NULL;
	}

	// replace newline or carr. return w/ NULL
        int pos;
        if (pos = strcspn(buffer, "\n\r"))
            buffer[pos] = '\0';
	return buffer;
}
