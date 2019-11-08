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
Segment_t * segmentable = NULL;


void initialize()
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

   segmentable = malloc(sizeof(Segment_t));
   segmentable->allocated = FALSE;
   segmentable->start = (void*)mymemory;
   segmentable->size = MAXMEM;
   segmentable->next = NULL;

   
   printf("initialize> end\n");

}

void * mymalloc(size_t size)
{
   printf("mymalloc> start\n");
   // implement the mymalloc functionality
   Segment_t * seg = findFree (segmentable, size);
   if(seg != NULL){
      Segment_t * segmentnew = malloc(sizeof(Segment_t));
      segmentnew->allocated = FALSE;
      segmentnew->start = seg->start;
      segmentnew->size = seg->size;

      seg->allocated = TRUE;
      seg->size = size;
      insertAfter(seg, segmentnew);
      printf ("mymalloc> end\n");
      return seg->start;

   }

}

void myfree(void * ptr)
{
   printf( "myfree> start\n");

   printf("myfree> end\n");

}

void mydefrag(void ** ptrlist)
{
   printf("mydefrag> start\n");

   printf("mydefrag> end\n");

}


// helper functions for management segmentation table
Segment_t * findFree(Segment_t * list, size_t size)
{
   printf ( "findFree> start\n");
	while (((list->size) < size) || ((list->allocated) == TRUE)) {
      if (list->next == NULL){
         return NULL;
      }
      list = list->next;
   }
   return list;

}

void insertAfter(Segment_t * oldSegment, Segment_t * newSegment)
{
   newSegment->next = oldSegment->next;
   oldSegment->next = newSegment;

}

Segment_t * findSegment(Segment_t * list, void * ptr)
{

}

int isPrintable(int c)
{
   if (c >= 0x20 && c <= 0x7e) return c ;
   return 0 ;

}

void printmemory()
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
   
   while (segmentable != NULL && segmentable <= MAXMEM){
      segmentable->next;
      n++;
   }
  
   printf(" Segment %d\n     allocated = %s\n     start = %p\n     size = %d\n", n, segmentable->allocated ? "TRUE" : "FALSE", segmentable->start, segmentable->size);

}

void printsegmentdescriptor(Segment_t * descriptor)
{
      printf("\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE")) ;
      printf("\tstart     = %p\n" , descriptor->start) ;
      printf("\tsize      = %lu\n", descriptor->size) ;

}