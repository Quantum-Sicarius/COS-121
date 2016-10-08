# Variables
CC = g++
FLAGS = -Wall -Werror -pedantic -std=c++11
OBJECTS = nullObject.o container.o auditorium.o integer.o dynamicArrayList.o listAsVector.o listAsSLL.o listAsDLL.o
OBJECTS_TEST = $(OBJECTS) catchConfig.o testMain.o

#main
main: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@

testMain: $(OBJECTS_TEST)
	$(CC) $(FLAGS) $(OBJECTS_TEST) -o $@


#build
testMain.o: test/testMain.cpp
	$(CC) $(FLAGS) -c test/testMain.cpp
catchConfig.o: libs/catch.hpp test/catchConfig.cpp
	$(CC) $(FLAGS) -c test/catchConfig.cpp
main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp
nullObject.o: libs/object.hpp libs/nullObject.hpp src/nullObject.cpp
	$(CC) $(FLAGS) -c src/nullObject.cpp
container.o: libs/object.hpp libs/container.hpp src/container.cpp
	$(CC) $(FLAGS) -c src/container.cpp
auditorium.o: libs/object.hpp libs/auditorium.hpp src/auditorium.cpp
	$(CC) $(FLAGS) -c src/auditorium.cpp
integer.o: libs/object.hpp libs/integer.hpp src/integer.cpp
	$(CC) $(FLAGS) -c src/integer.cpp
dynamicArrayList.o: libs/listAsArray.hpp libs/dynamicArrayList.hpp src/dynamicArrayList.cpp
	$(CC) $(FLAGS) -c src/dynamicArrayList.cpp
listAsVector.o: libs/listAsArray.hpp libs/listAsVector.hpp src/listAsVector.cpp
	$(CC) $(FLAGS) -c src/listAsVector.cpp
listAsSLL.o: libs/list.hpp libs/listAsSLL.hpp src/listAsSLL.cpp
	$(CC) $(FLAGS) -c src/listAsSLL.cpp
listAsDLL.o: libs/listAsSLL.hpp libs/listAsDLL.hpp src/listAsDLL.cpp
	$(CC) $(FLAGS) -c src/listAsDLL.cpp

#other functions
clean:
	rm *.o main *.tar.gz

doxygen:
#create doxygen documentation

package:
#package all the files into a .tar.gz

# Run
run:
	@echo "Start build at: "
	@date
	@make main
	@echo "Build stopped at: "
	@date
	./main

# Test
runTest:
	@echo "Start build at: "
	@date
	@make testMain
	@echo "Build stopped at: "
	@date
	./testMain
