IDIR =./include
SRC =./src/
CC=g++
FLAGS=-std=c++11
NAME=simulador
all:
	${CC} -o ${NAME} ${SRC}* -I ${IDIR} ${FLAGS}
