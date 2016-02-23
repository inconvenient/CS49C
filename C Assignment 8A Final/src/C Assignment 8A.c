#include <stdio.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define TRACE(x) x;
#else
#define TRACE(x) ;
#endif

#define MThd 0x4D546864 // Header ID "MThd"
#define MTrk 0x4D54726B // Track ID  "MTrk"

#define TICKS_PER_BEAT   60
#define NOTE_OFF       0x80
#define NOTE_ON        0x90
#define META_EVENT     0xFF
#define END_OF_TRACK   0x2F

#define put2bytes(data, fp) \
  putc((data) >> 8, fp);    \
  putc((data), fp);

#define put4bytes(data, fp) \
  putc((data) >> 24, fp);   \
  putc((data) >> 16, fp);   \
  putc((data) >> 8, fp);    \
  putc((data), fp);

// Track data
char track[500];
unsigned nbytes = 0;

void add_note(char pitch, char velocity, char ticks) {
	TRACE(printf("add_note(%d, %d, %d)\n", pitch, velocity, ticks))

	// NOTE_ON event
	track[nbytes++] = 0;
	track[nbytes++] = NOTE_ON;
	track[nbytes++] = pitch;
	track[nbytes++] = velocity;

	// NOTE_OFF event
	track[nbytes++] = ticks;
	track[nbytes++] = NOTE_OFF;
	track[nbytes++] = pitch;
	track[nbytes++] = velocity;
}

void end_of_track() {
	// END_OF_TRACK event
	track[nbytes++] = TICKS_PER_BEAT;
	track[nbytes++] = META_EVENT;
	track[nbytes++] = END_OF_TRACK;
	track[nbytes++] = 0;
}

int main(void) {
	char in_name[] = "notes.txt";
	char out_name[] = "notes.mid";
	FILE *in_fp, *out_fp;    // pointers to FILE structure

	// Open the input file and check for error
	// YOUR CODE HERE #1
	in_fp = fopen(in_name, "r");
	if ((in_fp = fopen(in_name, "r")) == NULL) {
		fprintf(stderr, "Error when opening \"%s\"\n", in_name);
		exit(EXIT_FAILURE);
	}

	// Create the track events
	unsigned pitch, velocity, ticks;
	while (EOF != fscanf(in_fp, "%d %d %d", &pitch, &velocity, &ticks)) {
		add_note((char) pitch, (char) velocity, (char) ticks);
	}
	end_of_track();

	// Open the output file and check for error
	// YOUR CODE HERE #3
	out_fp = fopen(out_name, "w");
	if ((out_fp = fopen(out_name, "w")) == NULL) {
		fprintf(stderr, "Error when closing \"%s\"\n", out_name);
		exit(EXIT_FAILURE);
	}

	// Write the MIDI header: 14 bytes
	put4bytes(MThd, out_fp);    // Header ID
	put4bytes(6, out_fp);       // Header length
	put2bytes(1, out_fp);       // Format type 1
	put2bytes(1, out_fp);       // Number of tracks 1
	put2bytes(TICKS_PER_BEAT, out_fp);

	// Write the track header: 8 bytes
	put4bytes(MTrk, out_fp);    // Track ID
	put4bytes(nbytes, out_fp);  // Track length in bytes

	// Write the track events
	int i;
	for (i = 0; i < nbytes; i++) {
		putc(track[i], out_fp);
	}
	/* YOUR CODE HERE #4 */

	// Close the input and output files, while checking of errors
	// YOUR CODE HERE #5
	if (fclose(in_fp) == EOF || fclose(out_fp) == EOF) {
		fprintf(stderr, "Error while closing files :(\n");
	}

	printf("%s has %u bytes\n", out_name, nbytes + 22);

	return 0;
}

