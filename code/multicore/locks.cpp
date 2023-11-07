// Can be compiled on the Mac, Windows and Linux.
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

using std::cout;
using std::endl;
using std::vector;
using std::thread;
using std::chrono::milliseconds;
using std::mutex;

void worker(uint32_t thread_id)
{
    while (true) {
        cout << "Thread: " << thread_id << " entering CS." << endl;
        std::this_thread::sleep_for(milliseconds(500));
        cout << "Thread: " << thread_id << " leaving CS." << endl;
    }
}

int main(int argc, char ** argv)
{
    uint32_t max_threads = thread::hardware_concurrency();
    vector<thread *> threads(max_threads);

    // Launch all the threads.
    for (uint32_t i = 0; i < max_threads; i++)
        threads[i] = new thread(worker, i);

    // Cntrl-C required.
    for (uint32_t i = 0; i < max_threads; i++)
    {
        threads[i]->join();
    }
    return 0;
}