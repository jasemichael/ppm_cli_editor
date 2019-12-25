#include "ThreadedGrid.h"
#include <iostream>

ThreadedGrid::ThreadedGrid( )
    : NumberGrid(){}

ThreadedGrid::ThreadedGrid( const int& height, const int& width )
    : NumberGrid(height, width){}

ThreadedGrid::~ThreadedGrid( ){}

void ThreadedGrid::calculateAllNumbers( ){
    unsigned int max_threads = std::thread::hardware_concurrency( );
    std::vector< std::thread > threads;
    unsigned int i;
    int j;
    for( j = 0; j < getNumbers().size(); j++ ) {
        tasks.push_back( j );
    }
    for( i = 0; i < max_threads; i++ ) {
        threads.push_back( std::thread( &ThreadedGrid::worker, this ) );
    }

    for( i = 0; i < max_threads; i++ ) {
        threads[ i ].join( );
    }
}

void ThreadedGrid::worker( ){
    int row, column, num;
    std::vector<int> values;
    while( !tasks.empty( ) ){
        values.clear();
        tasks.pop_back(values, 1);
        row = values[0]/getHeight();
        column = values[0]/getWidth();
        num = calculateNumber(row,column);
        setNumber(row, column, num);
    }
}