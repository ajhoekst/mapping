#include <iostream>
#include "../include/timer.hpp"

using namespace std;

int main(int argc, const char** argv)
{
    Timer t(10);
    t.start();
    cout << "Starting" << endl;
    for (;;)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "." << endl;
        t.step();
        if (t.hasTriggered())
        {
            cout << "Done!" << endl;
            break;
        }
    }
    return 0;
}