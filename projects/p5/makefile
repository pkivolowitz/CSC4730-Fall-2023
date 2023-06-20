SYS := $(shell g++ -dumpmachine)
ifneq (, $(findstring apple, $(SYS)))
CFLAGS	= -g -Wall -std=c++11 
LFLAGS	= -lpthread
else
CFLAGS	= -g -Wall -std=c++11
LFLAGS	= -lpthread
endif

CC		= g++

slab_s = slab.cpp
obj_s  = $(slab_s:.cpp=.o)
deps_s = $(slab_s:.cpp=.d)

next_n = next.cpp
obj_n  = $(next_n:.cpp=.o)
deps_n = $(next_n:.cpp=.d)

best_b = best.cpp
obj_b  = $(best_b:.cpp=.o)
deps_b = $(best_b:.cpp=.d)

slab: slab.o
	$(CC) $^ -o $@ $(LFLAGS)

next: next.o
	$(CC) $^ -o $@ $(LFLAGS)

best: best.o
	$(CC) $^ -o $@ $(LFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

# $(RM) is rm -f by default
clean:
	$(RM) *.o $(deps_s) a.out core slab
	$(RM) $(deps_n) next
	$(RM) $(deps_b) best


-include $(deps_s)
-include $(deps_n)
-include $(deps_b)
