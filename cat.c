#include<stdio.h>


int write_file(char *arg)
{

// We assume argv[1] is a filename to open
        FILE *file = fopen( arg, "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
            int x;
            /* read one character at a time from file, stopping at EOF, which
               indicates the end of the file.  Note that the idiom of "assign
               to a variable, check the value" used below works because
               the assignment statement evaluates to the value assigned. */
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                printf( "%c", x );
            }
            fclose( file );
        }
        return 0;


}

int main ( int argc, char *argv[] )
{
    if ( argc < 2 ) /* argc should be greater than 2 for correct execution */
    {
        
        printf("Error");
    }
    else 
    {
        for(int i = 1; i <= argc - 1; i++) {
        	write_file(argv[i]);
        }
        printf("\n");

       

    }

 }