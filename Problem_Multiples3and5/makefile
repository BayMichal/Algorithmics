#/*******************************************************************
#* Filename:   Makefile
#* Author:     Michał Bajkos
#* Details:    Simple system-build for gcc project
#*********************************************************************/
CONFIG_DIR?=build


main:  clean CONFIG_DIR
	echo ${CONFIG_DIR}
	gcc -Wall -g  -c main.c -o ${CONFIG_DIR}/main.o 
	gcc -Wall -g  -c logic.c -o ${CONFIG_DIR}/logic.o
	gcc -o  ${CONFIG_DIR}/Collision.exe ${CONFIG_DIR}/main.o ${CONFIG_DIR}/logic.o
	./build/Collision.exe

clean:
	rm -f -r $(CONFIG_DIR)


CONFIG_DIR:
	mkdir build

