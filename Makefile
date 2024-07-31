CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -w

EXEC = chess
CCFILES = $(shell find . -name "*.cc")
OBJECTS = ${CCFILES:.cc=.o}
DEPENDS = ${CCFILES:.cc=.d}

X11_LIB_PATH = /opt/X11/lib
X11_INC_PATH = /opt/X11/include

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L$(X11_LIB_PATH) -lX11

%.o: %.cc
	${CXX} ${CXXFLAGS} -I$(X11_INC_PATH) -c $< -o $@

clean:
	rm -rf ${OBJECTS} ${DEPENDS} ${EXEC}

-include ${DEPENDS}
