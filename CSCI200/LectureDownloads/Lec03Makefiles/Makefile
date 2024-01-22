TARGET = Lec03
SRC_FILES = main.cpp
# NO EDITS BELOW THIS LINE
CXX = g++
OBJECTS = $(SRC_FILES:.cpp=.o)
ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)