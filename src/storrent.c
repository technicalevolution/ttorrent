#include <stdio.h>
#include <unistd.h>

void usage( void );

int main( int argc, char **argv, char **env ) {

  char *file;
  char *output;
  
  int c;

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


  return 0;

}

void usage(void) {

  printf("Usage:\n");
  printf("\n");
  printf("\tstorrent -f <torrent file> -o <torrent output directory>");
  printf("\n");

}
