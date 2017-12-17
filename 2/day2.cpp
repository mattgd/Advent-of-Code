#include <iostream>
#include <climits>
#include <cctype>

using namespace std;

/**
 * Eats characters until a new digit is reached.
 * @param stream The FILE stream to get characters from.
 * @return true if there was a newline break and false if not.
 */
bool eatCharacters( FILE *stream )
{
    char ch;
    bool isNewline = false;
    
    while ( ( ch = getc( stream ) ) != EOF ) {
        if ( isdigit( ch ) ) {
            ungetc( ch, stream );
            break;
        }

        if ( ch == '\n' ) {
            isNewline = true;
        }
    }

    return isNewline || ch == EOF;
}

/**
 * Main function for Day 2.
 */
int main( int argc, char* argv[] )
{
    if ( argc < 2 ) {
        cout << "You must specify an input file." << endl;
        return EXIT_FAILURE;
    }

    FILE *stream = fopen( argv[ 1 ], "r" );
    if ( stream == NULL ) {
        cout << "Invalid input file." << endl;
        return EXIT_FAILURE;
    }
    
    int min = INT_MAX;
    int max = INT_MIN;
    int value;
    int checksum = 0;

    while ( fscanf( stream, "%d", &value ) == 1 ) {
        if ( value < min ) {
            min = value;
        }
        
        if ( value > max ) {
            max = value;
        }
        
        if ( eatCharacters( stream ) ) {
            checksum += max - min;
            min = INT_MAX;
            max = INT_MIN;
        }
    }

    fclose( stream );
    cout << "Checksum: " << checksum << endl;
    return EXIT_SUCCESS;
}