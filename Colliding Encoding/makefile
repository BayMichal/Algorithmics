CONFIG_DIR?=build


main:  clean CONFIG_DIR
	echo ${CONFIG_DIR}
	gcc -Wall -g  -c main.c -o ${CONFIG_DIR}/main.o
	gcc -Wall -g  -c Intern.c -o ${CONFIG_DIR}/Intern.o
	gcc -o  ${CONFIG_DIR}/kickstar_one.exe ${CONFIG_DIR}/Intern.o ${CONFIG_DIR}/main.o 
	./build/kickstar_one.exe

clean:
	rm -r ${CONFIG_DIR};


CONFIG_DIR:
	mkdir build

