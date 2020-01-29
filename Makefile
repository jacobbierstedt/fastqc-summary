pname := fastqc-summary

CXX := g++
CXXFLAGS := -std=c++11

srcfs := $(shell find . -name "*.cpp")
objs  := $(patsubst %.cpp, %.o, $(srcfs))

all: $(pname)

$(pname): $(objs)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(pname) $(objs) $(LDLIBS)

depend: .depend

.depend: $(srcfs)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objs)

dist-clean: clean
	rm -f *~ .depend

include .depend
