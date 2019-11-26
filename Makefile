IDIR =./include
SRC =./src/
CC=g++
FLAGS=-std=c++11
NAME=Analiser
all:
	${CC} -o ${NAME} ${SRC}* -I ${IDIR} ${FLAGS}
