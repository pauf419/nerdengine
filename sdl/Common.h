#ifndef __COMMON__
#define __COMMON__

#include <iostream>
using namespace std;

struct CARTPoint {
    double x;
    double y;
};

class Common
{
public:
    Common();
    static void log_CARTP_stats(CARTPoint p);
};

#endif