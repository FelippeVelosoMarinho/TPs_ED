#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <threads.h>

class Tmp
{
public:
    float diffUserTime(struct rusage *start, struct rusage *end);
    float diffSystemTime(struct rusage *start, struct rusage *end);
};