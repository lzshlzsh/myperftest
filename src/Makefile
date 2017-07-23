NEED_AUTO_DEP := 1
NEED_AUTO_RULE_COM := 1
NEED_GTESTX := 1

TARGET := myperftest
include ../Makefile.env

${TARGET}: %: ${OBJ}
	${CXX} ${CXXFLAGS} -o $@ $^ ${LDFLAGS}
