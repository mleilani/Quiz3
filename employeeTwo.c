#include <string.h> 

#include "employee.h" 

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,  

int (*functionPtr)(const void *, PtrToConstEmployee)) 

{ 

  PtrToConstEmployee endPtr = ptr + tableSize; 

  for(; ptr < endPtr; ptr++) 

    if ((*functionPtr)(targetPtr, ptr) == 0) 

      return (PtrToEmployee) ptr; 

  return NULL; 

} 

//The functionPtr will point to one of these comparison functions to perform a check 

static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) 

{ 

  return * (long *) targetPtr != tableValuePtr->number; //const void *targetPtr ==> typecast as int pointer then dereference 

} 

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) 

{ 

  return strcmp((char *) targetPtr, tableValuePtr->name);//const void *targetPtr ==> typecast as char pointer then pass into strcmp() 

} 