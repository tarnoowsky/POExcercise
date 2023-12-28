CXX = g++
CXXFLAGS = -g -Wall -pedantic

TARGET1 = testMap
TARGET2 = testLibrary

SRC1 = testMap.cpp
SRC2 = Library.cpp

HEADERS1 = Employee.h Map.h
HEADERS2 = Map.h

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(SRC1) $(HEADERS1)
	$(CXX) $(CXXFLAGS) $(SRC1) -o $(TARGET1)

$(TARGET2): $(SRC2) $(HEADERS2)
	$(CXX) $(CXXFLAGS) $(SRC2) -o $(TARGET2)

clean:
	rm -f $(TARGET1) $(TARGET2)
