#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int
main(int argc, char *argv[])
{
   if ( argc != 3 ) {
       printf( "Usage: %s [list] [list length]\n", argv[0] );
       exit( EXIT_FAILURE );
   }

   FILE * fp;
   char * line = NULL;
   size_t len = 0;

   int list_len = atoi( argv[2] );
   int *list = (int *) malloc( sizeof(int) * list_len );

   fp = fopen( argv[1], "r" );
   if ( fp == NULL )
       exit( EXIT_FAILURE );

   for (int i = 0; i < list_len; i++) {
       getline( &line, &len, fp ); 
       list[i] = atoi( line );
   }

   merge_sort(list, list_len);

   print_arr(list, list_len);

   if (line)
       free( line );
   exit( EXIT_SUCCESS );
}
