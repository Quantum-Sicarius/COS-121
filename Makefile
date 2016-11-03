CXX = clang++
BUILD := debug

# Check if the COMPILER variable is set. If it is set the variable CXX to it.
ifneq ($(strip $(COMPILER)),)
 CXX = $(COMPILER)
endif

ifndef CXXFLAGS
 cxxflags.release := -Wall -pedantic -std=c++14
 cxxflags.debug := ${cxxflags.release} -fcolor-diagnostics -g -fsanitize=address -fstack-protector
 CXXFLAGS := ${cxxflags.${BUILD}}
 runflags.release :=
 runflags.debug := ASAN_OPTIONS=symbolize=1 ASAN_SYMBOLIZER_PATH=$(shell which llvm-symbolizer)
 RUNFLAGS := ${runflags.${BUILD}}
endif

OBJECTS = $(addprefix build/,$(notdir object.o nullObject.o auditorium.o integer.o dynamicSizedMatrix.o flexiMatrix.o))
OBJECTS_TEST = $(OBJECTS) build/catchConfig.o build/testMain.o

# Make build directory.
$(shell mkdir -p build)

.PHONY: test.out
test.out: $(OBJECTS_TEST)
	$(CXX) $(CXXFLAGS) $(OBJECTS_TEST) -o $@

.PHONY: main.out
main.out: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $@

build/testMain.o: test/testMain.cpp
	$(CXX) $(CXXFLAGS) -c test/testMain.cpp -o $@
build/catchConfig.o: libs/catch.hpp test/catchConfig.cpp
	$(CXX) $(CXXFLAGS) -c test/catchConfig.cpp -o $@
build/object.o: libs/object.hpp src/object.cpp
	$(CXX) $(CXXFLAGS) -c src/object.cpp -o $@
build/nullObject.o: libs/object.hpp libs/nullObject.hpp src/nullObject.cpp
	$(CXX) $(CXXFLAGS) -c src/nullObject.cpp -o $@
build/container.o: libs/object.hpp libs/container.hpp src/container.cpp
	$(CXX) $(CXXFLAGS) -c src/container.cpp -o $@
build/auditorium.o: libs/object.hpp libs/auditorium.hpp src/auditorium.cpp
	$(CXX) $(CXXFLAGS) -c src/auditorium.cpp -o $@
build/integer.o: libs/object.hpp libs/integer.hpp src/integer.cpp
	$(CXX) $(CXXFLAGS) -c src/integer.cpp -o $@
build/dynamicSizedMatrix.o: libs/matrix.hpp libs/dynamicSizedMatrix.hpp src/dynamicSizedMatrix.cpp
	$(CXX) $(CXXFLAGS) -c src/dynamicSizedMatrix.cpp -o $@
build/flexiMatrix.o: libs/matrix.hpp libs/flexiMatrix.hpp src/flexiMatrix.cpp
	$(CXX) $(CXXFLAGS) -c src/flexiMatrix.cpp -o $@

.PHONY: clean
clean:
	rm -rf *.o *.out *.tar.gz build

.PHONY: doxygen
doxygen:
#create doxygen documentation

.PHONY: package
package:
#package all the files into a .tar.gz

# Run
run:
	@echo "Start build at: "
	@date
	@make main.out
	@echo "Build stopped at: "
	@date
	./main.out

# Test
.PHONY: test
test:
	@echo "Start build at: "
	@date
	@make test.out
	@echo "Build stopped at: "
	@date
	$(RUNFLAGS) ./test.out
