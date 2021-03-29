#include <fos.h>

#ifndef MULTICOUNTER_H
#define MULTICOUNTER_H

namespace FOS{

class multicounter
{
    static  int counters[10];
    public:

    static void resetCounter(int counterIndex);
    static int getCount(int counterIndex);
    static boolean increaseCounter(int counterIndex);
    static boolean increaseCounter(int counterIndex, int step);


}
}
#endif