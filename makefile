prog: main.o proj.o
	@echo "Linking files..."
	gcc -m64 main.o proj.o -o prog
	@echo "SUCCESS\n\n"

main.o: main.c
	@echo "Compiling C FUNCTION..."
	gcc -m64 -c main.c -o main.o
	@echo "SUCCESS\n\n"
	
proj.o: proj.asm
	@echo "Compiling ASM FUNCTION..."
	nasm -f elf64 proj.asm -o proj.o
	@echo "SUCCESS\n\n"
