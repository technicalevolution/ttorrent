#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

void usage( void );

int main( int argc, char **argv, char **env ) {

  char *file = NULL;
  char *output = NULL;
  
  int c;

  struct stat *statbuf;

  while ((c = getopt (argc, argv, "f:o:")) != -1)
    switch (c)
      {
        case 'f':
          file = optarg;
          break;
        case 'o':
          output = optarg;
          break;
        case '?':
          usage();
          return 1;
        default:
          usage();
      }

  if( file == NULL ) {
    usage();
    return 1;
  } else if ( output == NULL ) {
    usage();
    return 1;
  }

  statbuf = (struct stat *)calloc(1, sizeof(struct stat)); 
  if(stat(file, statbuf) != 0) {
    printf("There was a problem acessing the file: %s\n", file);
    return 1;
  }
  free(statbuf);

  

  
  
  
  
  return 0;

}

void usage(void) {

  printf("Usage:\n");
  printf("\n");
  printf("\tttorrent -f <torrent file> -o <torrent output directory>");
  printf("\n");

}
