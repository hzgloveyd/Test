SOURCE = gl.c
OUTPUT = gl
CC = gcc
CLIBS = -lGL -lGLU -lglut -lglfw -lGLEW
all:
	$(CC) $(SOURCE) -o $(OUTPUT) $(CLIBS)

clean:
	@echo Cleaning up...
	@rm $(OUTPUT)
	@echo done.
