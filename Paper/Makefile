CPP = clang++
CFLAGS = -std=c++11 -stdlib=libc++
LFLAGS = -Wall -Wextra


.PHONY: all clean

all: PaperCode

PaperCode: PaperCode.cpp
	$(CPP) $(CFLAGS) $^ -o $@

clean:
	rm -f PaperCode
