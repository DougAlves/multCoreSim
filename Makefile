IDIR =./include
SRC =./src/
CC=g++
FLAGS=

all:
	${CC} -o multCore ${SRC}* -I ${IDIR} ${FLAGS}
