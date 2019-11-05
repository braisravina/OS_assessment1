/* mymemory.c
 * 
 * provides interface to memory management
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "mymemory.h"


// our memory
Byte        mymemory [MAXMEM] ;
Segment_t * segmenttable = NULL;


void initialize ()
{
   printf ( "initialize> start\n");

   // set mymemory to \0
   int n=0;
   for (n; n<MAXMEM; n++){
      mymemory[n] = '\0';
   }

   // create segment table
   // contains one segment description that declares the whole memory
   // as one free segment
   //
   // create a single segment descriptor

   // initialise the segment

   //segmenttable = malloc(sizeof(Segment_t));
   Segment_t segment0;
   segment0.allocated = FALSE;
   segment0.start = &mymemory[0];
   segment0.size = MAXMEM;
   segment0.next = NULL;
   

   printf ( "initialize> end\n");
}

//void myfree ( void * ptr )
//{

//}

void * mymalloc ( size_t size )
{
   printf ( "mymalloc> start\n");

   // implement the mymalloc functionality
}

void myfree ( void * ptr )
{
   printf ( "myfree> start\n");

}

void mydefrag ( void ** ptrlist)
{
   printf ( "mydefrag> start\n");

}


// helper functions for management segmentation table
Segment_t * findFree ( Segment_t * list, size_t size )
{
   printf ( "findFree> start\n");


}

void insertAfter ( Segment_t * oldSegment, Segment_t * newSegment )
{
}

Segment_t * findSegment ( Segment_t * list, void * ptr )
{
}

int isPrintable ( int c )
{
   if ( c >= 0x20 && c <= 0x7e ) return c ;

   return 0 ;
}

void printmemory ()
{
   int n, i;
   char j;
   for(n=0; n<MAXMEM; n++){
      printf("[%4d]",n);
      for(i=0; i<10; i++){
         n = n+1;
         printf(" %02x ", mymemory[n]);
      }
      n = n-10;
      printf(" |  ");
      for(i=0; i<10; i++){
         n = n+1;
         j = mymemory[n];
         if (j>=0x20 && j<=0x7e){
            printf("%c", mymemory[n]);
         }
         else{
            printf(".");
         }
      }
      n = n-1;
      printf("\n");
   }

}

void printsegmenttable()
{
   int n = 0;
   Segment_t segment0;
   while (&segment0 != NULL && &segment0 <= MAXMEM) {
      segment0.next;
      n++;
   }
  
   printf("Segment %d\n     allocated = %s\n     start = %p\n     size = %d\n", n, segment0.allocated ? "TRUE" : "FALSE", segment0.start, segment0.size);

}

void printsegmentdescriptor ( Segment_t * descriptor )
{
      printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
      printf ( "\tstart     = %p\n" , descriptor->start ) ;
      printf ( "\tsize      = %lu\n", descriptor->size  ) ;
}

int main()
{
   initialize();
   printmemory();
   printsegmenttable();
   
}
