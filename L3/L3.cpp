#include <iostream>
#include <boost/timer.hpp>
#include <boost/progress.hpp>
using namespace boost;
using namespace std;

int main()
{
    timer t;

    for (int i = 0; i < 1000000000; ++i) {};
    cout << "time elapsed:" << t.elapsed() << "s" << endl;

    t.restart();
    for (int i = 0; i < 1000000000; ++i) {};
    cout << "time elapsed:" << t.elapsed() << "s" << endl;

    cout << "timer max timespan:" << t.elapsed_max() << "s" << endl;
    cout << "timer min timespan:" << t.elapsed_min() << "s" << endl;

    {
        boost::progress_timer t;
        for (int i = 0; i < 1000000000; ++i) {};
    }

    {
        boost::progress_timer t;
        for (int i = 0; i < 1000000000; ++i) {};
    }
}

