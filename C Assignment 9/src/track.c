/*
 * track.c
 */

#include "track.h"
#include "fgetline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Track *get_track(FILE *fp)
{
	// Get a track of the database file
	Track *tp = NULL;
	char *line;

	// Try to get the next line from the file
	if(line = fgetline(fp))
	{
		// Allocate a track structure
		tp = (Track *) malloc(sizeof(Track));
		// Allocate a string for artist and copy from line buffer
		tp->artist = (char *) malloc(strlen(line)+1); // with '\0'
		strcpy(tp->artist, line);

		// Allocate a string for title and copy from line buffer
		line = fgetline(fp);
		tp->title = (char *) malloc(strlen(line)+1); // With '\0'
		strcpy(tp->title, line);
	}
	return tp;
}

void free_track(Track *tp)
{
	// Free up the track's memory resource
	free(tp->artist);
	free(tp->title);
	free(tp);
}

void show_track(const Track *tp, FILE *fp)
{
	// Display track info.
	fprintf(fp, "\"%s\" by %s\n", tp->title, tp->artist);
}
