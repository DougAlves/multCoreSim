IDIR =./include
SRC =./src/
CC=gcc
FLAGS=-ln 

all:
	${CC} -o multCore ${SRC}* -I ${IDIR} ${FLAGS}
