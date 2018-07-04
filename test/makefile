APP=test
CXXFLAGS=-Wall -std=c++14

src=$(shell find ./ -type f -name '*.cpp')
obj=$(src:.cpp=.o)

build_all: $(obj)
	$(CXX) $^ -o $(APP)

.PHONY: clean
clean:
	rm -f $(obj) $(APP)
