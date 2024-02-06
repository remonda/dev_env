OUTPUT_DIR=./output

BUILD_DIR=${OUTPUT_DIR}/build

TARGET_DIR=${OUTPUT_DIR}/bin

TARGET_EXEC=target

SRC_DIR=./src

INC_DIR=./incldue

TEST_DIR=./test

SRCS=$(shell find ${SRC_DIR} -name '*.cpp' -or -name '*.c')

OBJS=$(SRCS:%=${BUILD_DIR}/%.o)

INC_FLAGS=$(addprefix -I, ${INC_DIR})

INC_FLAGS += -I/usr/local/include -I/usr/local/opt/llvm/include

LD_FLAGS= -L/usr/local/lib -L/usr/local/opt/llvm/lib -lpthread

CXX=g++

CXXFLAGS= -std=c++17 -g -Wall -Wextra

CXXFLAGS+= ${INC_FLAGS}


# build step
${TARGET_DIR}/${TARGET_EXEC}: ${OBJS}
	mkdir -p $(dir $@)
	${CXX} ${OBJS} -o $@ ${LD_FLAGS}

${BUILD_DIR}/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -c $< -o $@

.PHONY: clean

clean:
	rm -r ${OUTPUT_DIR}