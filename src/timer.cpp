#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        cout << "Usage: timer ms" << endl;
        return 1;
    }
    
    cout << argv[1] << endl;
    this_thread::sleep_for(chrono::milliseconds(stoi(argv[1])));
    cout << "Done!" << endl;
    return 0;
}