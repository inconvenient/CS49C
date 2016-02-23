#include <stdio.h>
#include <stdlib.h>

// The program had issues compiling on my computer...

int main(void)
{
    unsigned matrix[3][12];
    unsigned final[12][3];
    int i, j;
    
    char in_name[] = "numbers.txt";
    char out_name[] = "notes.txt";
    FILE *in_fp, *out_fp;    // pointers to FILE structure
    
    
    // Open the input file and check for error
    // YOUR CODE HERE #1
    in_fp = fopen(in_name, "r");
    if ((in_fp = fopen(in_name, "r")) == NULL)
    {
        fprintf(stderr, "Error when opening \"%s\"\n", in_name);
        exit(EXIT_FAILURE);
    }
    // Read the 3 by 12 matrix of numbers, while checking for errors
    // YOUR CODE HERE #2
    // Read the chars and place it into the temp array.
    else
    {
        while(!feof (in_fp)) // While file is not at the end
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 12; j++)
                {
                    fscanf(in_fp, "%d", matrix[i][j]); // Scan each number in textfile, place into matrix.
                    // matrix is now filled with the midi notes.
                }
            }       
        }
    }

    // *** Open the output file and check for error    
    // YOUR CODE HERE #3
    out_fp = fopen(out_name, "w");
    if ((out_fp = fopen(out_name, "w")) == NULL)
    {
        fprintf(stderr, "Error when closing \"%s\"\n", out_name);
        exit(EXIT_FAILURE);
    }
    // *** Write as 12 by 3 matrix of numbers, while checking for errors
    // YOUR CODE HERE #4
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 12; j++)
        {
            final[j][i] = matrix[i][j]; // Transposed matrix into final.
        }
    }
    
    // CHECK FOR ERRORS!!!
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 12; j++)
        {
            fprintf(out_fp, "%d\t", final[i][j]);
        }
    }
    
    // *** Close the input and output files, while checking of errors
    // YOUR CODE HERE #5
    
    // CHECK FOR ERRORS!!!
    fclose(in_fp);
    fclose(out_fp);
    
    

    
    return 0;
}