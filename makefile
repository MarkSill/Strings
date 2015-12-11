GXX := g++-5
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -std=c++17 -g -Wall

lllstr: $(OBJ_FILES)
	$(GXX) $(CC_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	mkdir -p obj
	$(GXX) $(CC_FLAGS) -c -o $@ $<

test: lllstr
	gdb -ex run lllstr

nogdb: lllstr
	./lllstr

clean:
	rm -r -f obj lllstr
