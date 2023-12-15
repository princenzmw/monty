FINAL = monty
MFILES = *.c
HEADER = monty.h

COMP = gcc
MFLAGA = -Wall
MFLAGB = -Werror
MFLAGC = -Wextra
MFLAGD = -pedantic
MFLAGE = -std=c89
MFLAGF = -g
MFLAGZ = ${MFLAGA} ${MFLAGB} ${MFLAGC} ${MFLAGD} ${MFLAGE} ${MFLAGF}

all:
	${COMP} ${MFLAGZ} ${MFILES} -o ${FINAL}

clean:
    rm -f ${FINAL}
