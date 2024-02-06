OUTPUT_DIR=./output

BUILD_DIR=${OUTPUT_DIR}/build

TARGET_DIR=${OUTPUT_DIR}/bin

TARGET_TEST_DIR=${BUILD_DIR}/test

TARGET_EXEC=target

TEST_EXEC=main_test

TARGET_TEST_DIR=${OUTPUT_DIR}/test

TARGET=${TARGET_DIR}/${TARGET_EXEC}

SRC_DIR=./src

INC_DIR=./

TEST_DIR=./test

SRCS=$(shell find ${SRC_DIR} -name '*.cpp' -or -name '*.c')

TEST_SRCS=$(shell find ${TEST_DIR} -name '*.cpp' -or -name '*.c')

OBJS=$(SRCS:%=${BUILD_DIR}/%.o)

TEST_OBJS=$(TEST_SRCS:%=${BUILD_DIR/%.o})

INC_FLAGS=$(addprefix -I, ${INC_DIR})

INC_FLAGS += -I/usr/local/include -I/usr/local/opt/llvm/include

LD_FLAGS= -L/usr/local/lib -L/usr/local/opt/llvm/lib -lpthread

CXX=g++

CXXFLAGS= -std=c++17 -g -Wall -Wextra

CXXFLAGS+= ${INC_FLAGS}

TEST_LD_FAGS= ${LD_FLAGS}

TEST_LD_FAGS+= -lglags -lgtest

# build step
# build src
${TARGET_DIR}/${TARGET_EXEC}: ${OBJS}
	mkdir -p $(dir $@)
	${CXX} ${OBJS} -o $@ ${LD_FLAGS}

${BUILD_DIR}/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -c $< -o $@

#build test
${TARGET_TEST_DIR}/${TEST_EXEC}: ${TEST_OBJS}
	mkdir -p $(dir $@)
	${CXX} ${TEST_OBJS} -o $@ ${TEST_LD_FLAGS}

${BUILD_DIR}/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -c $< -o $@

.PHONY: all buildall build buildtest test clean

build: ${TARGET_DIR}/${TARGET_EXEC}

buildtest: ${TARGET_TEST_DIR}/${TEST_EXEC}

clean:
	rm -r ${OUTPUT_DIR}
test:
	echo ${TEST_SRCS}
