#/*******************************************************************
#* Filename:   Makefile
#* Author:     Michał Bajkos
#* Details:    Simple system-build for gcc project
#*********************************************************************/
CONFIG_DIR?=build


main:  clean CONFIG_DIR
	echo ${CONFIG_DIR}
	gcc -Wall -g  -c main.c -o ${CONFIG_DIR}/main.o
	gcc -Wall -g  -c intern.c -o ${CONFIG_DIR}/intern.o
	gcc -Wall -g  -c md2.c -o ${CONFIG_DIR}/md2.o
	gcc -o  ${CONFIG_DIR}/kickstar_one.exe ${CONFIG_DIR}/intern.o ${CONFIG_DIR}/main.o ${CONFIG_DIR}/md2.o 
	./build/kickstar_one.exe

clean:
	rm -f -r $(CONFIG_DIR)



CONFIG_DIR:
	mkdir build

