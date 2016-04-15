#include <stdlib.h>
#include <stdio.h>
// Code from http://www.cplusplus.com/forum/general/30215/
char * copy_file(const char* srcfilename)
  {
  long  len;
  char* buf = NULL;
  FILE* fp  = NULL;

  // Open the source file
  fp = fopen( srcfilename, "rb" );
  if (!fp) return 0;

  // Get its length (in bytes)
  if (fseek( fp, 0, SEEK_END ) != 0)  // This should typically succeed
    {                                 // (beware the 2Gb limitation, though)
    fclose( fp );
    return 0;
    }

  len = ftell( fp );
  rewind( fp );

  // Get a buffer big enough to hold it entirely
  buf = (char*)malloc( len );
  if (!buf)
    {
    fclose( fp );
    return 0;
    }

  // Read the entire file into the buffer
  if (!fread( buf, len, 1, fp ))
    {
    free( buf );
    fclose( fp );
    return 0;
    }

  fclose( fp );

  // Open the destination file
  return buf;
  }
