/*  Program showing effect of page buffering in a VM system.
    Vary the array size keeping the number of samples to take constant.
    If the array is smallish, the pages are cached and the program will
    run quickly. If the array is huge, the program takes a long time to
    run even if the number of samples is kept the same. This shows the
    expense of random access over a large range of memory is slower due
    to cache misses.

    Perry Kivolowitz
    Carthage College
    Department of Computer Science
*/
#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <getopt.h>

int main(int argc, char ** argv) {
    size_t array_size = 1 << 12;
    uint64_t num_samples = 1 << 16;
    int64_t c;
    int64_t n;

    while ((c = getopt(argc, (char * const *) argv, "n:s:")) != -1) {
        switch (c) {
            case 's':
            case 'n':
                n = std::stoi(optarg);
                if (n < 1 || n > 30) {
                    std::cerr << "Argument to " << c << " ";
                    std::cerr << "must be in range of 1 to 30\n";
                    return 1;
                }
                n = 1 << n;
                if (c == 's')
                    array_size = n;
                else
                    num_samples = n;
                break;
            
            default:
                std::cerr << "Unknown option: " << c << std::endl;
                return 1;
        }
    }
    std::random_device rd;
	std::uniform_int_distribution<> u_dist(0, array_size - 1);
	std::mt19937 generator(rd());

	unsigned char * array = new unsigned char[array_size];
    auto start = std::chrono::high_resolution_clock::now();

    for (uint64_t counter = 0; counter <  num_samples; counter++) {
		size_t v = u_dist(generator);
        volatile unsigned char c = array[v];
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time: " << double(duration.count()) / 1000000.0 << std::endl;
	return 0;
}