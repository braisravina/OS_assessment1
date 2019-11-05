#include <stdio.h> 
#include <string.h> 
#include "mymemory.h"

int main()
{
    printf ( "shell> start\n");

    initialize() ;

    printmemory() ;
    printsegmentdescriptor(segmenttable) ;

    printf ( "shell> end\n");
    return 0; 
}