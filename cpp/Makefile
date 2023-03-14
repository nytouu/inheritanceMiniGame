include config.mk

SRC = main.cpp
OBJ = ${SRC:.cpp=.o}

all: clean tamagochi

tamagochi: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${OBJ} tamagochi

.PHONY: all tamagochi clean
