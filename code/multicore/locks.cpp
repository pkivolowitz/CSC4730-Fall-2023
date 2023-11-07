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

void worker(uint32_t thread_id, mutex * m)
{
	while (true) {
        while (!m->try_lock()) {
            cout << "Thread: " << thread_id << " failed to get lock\n";
            std::this_thread::sleep_for(milliseconds(100));
        }
		cout << "Thread: " << thread_id << " entering CS." << endl;
		std::this_thread::sleep_for(milliseconds(5));
        cout << "Thread: " << thread_id << " leaving CS." << endl;
        if (rand() % 999 != 0)
		    m->unlock();
        std::this_thread::yield();
	}
}

int main(int argc, char ** argv)
{
    srand((unsigned int) time(NULL));

	mutex m;

	uint32_t max_threads = thread::hardware_concurrency();
    vector<thread *> threads(max_threads);

    // Launch all the threads.
    for (uint32_t i = 0; i < max_threads; i++)
        threads[i] = new thread(worker, i, &m);

    // Cntrl-C required.
    for (uint32_t i = 0; i < max_threads; i++)
    {
        threads[i]->join();
    }
    return 0;
}