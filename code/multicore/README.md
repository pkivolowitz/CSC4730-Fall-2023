# Multicore Examples

## naked_counter.cpp

Demonstrates uncontrolled access to a shared resource (a counter). Exhibits the hidden update problem.

It is a useful jumping off point for a discussion of what "volatile" does. Demonstrate by building
with full optimization on - suddenly the hidden update problem goes away. Then, add "volatile" to
the counter the problem comes back. Explain that the full optimization of the non-volatile version
completely eliminates the actual computation as the compiler computes the ending values and just
returns them.

## slow.cpp

This adds a mutex around the handling of the counter, causing all threads to serialize.

## manual_reduction.cpp

Breaks the problem into separate pieces so that there is no shared resource. This is called
a reduction but is implemented by my own code.

## omp.cpp

This demonstrates both omp AND asking omp to perform the reduction automatically.
