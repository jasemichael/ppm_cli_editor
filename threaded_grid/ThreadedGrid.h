#ifndef THREADED_GRID_THREADEDGRID_H
#define THREADED_GRID_THREADEDGRID_H
#include "NumberGrid.h"
#include "ThreadedVector.h"
#include <thread>

class ThreadedGrid: public NumberGrid{
protected:
    ThreadedVector<int> tasks;
public:
    ThreadedGrid( );
    ThreadedGrid( const int& height, const int& width );
    virtual ~ThreadedGrid( );
    virtual void calculateAllNumbers( );
    virtual void worker( );
};
#endif //THREADED_GRID_THREADEDGRID_H
