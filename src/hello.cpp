#include <stdio.h>
#include <string>
#include "hello.h"

using namespace std;

void myPrintHelloMake(void) {

  printf("Hello makefiles!\n");

  return;
}

bool cmpcaseinsens(const string& a, const string& b)
{
    // Case insensitive Compare string. 
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}