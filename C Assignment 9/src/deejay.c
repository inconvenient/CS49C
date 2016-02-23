#include <stdio.h>
#include <stdlib.h>
#include "track.h"

int main(void)
{
	char tracks_file[] = "tracks.txt";
	FILE *trks_fp;

	// open the tracks database file
	if ((trks_fp = fopen(tracks_file, "r")) == NULL)
	{
		fprintf(stderr, "Error while opening \"%s\".\n", tracks_file);
		exit(EXIT_FAILURE);
	}

	// get tracks until EOF
	Track *tp;
	while (tp = get_track(trks_fp))
	{
		show_track(tp, stdout);
		free_track(tp);
	}

	// close the tracks database
	if (fclose(trks_fp) == EOF)
	{
		fprintf(stderr, "Error while closing \"%s\".\n", tracks_file);
		{
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
