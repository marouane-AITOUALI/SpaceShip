CFLAGS =  -O3 -Dmain=SDL_main
LDFLAGS = -lm -lmingw32 -lSDL2main -lSDL2
SDL2_INCLUDE_DIR = include
SDL2_LIBRARIES_DIR =lib

INC = sdl2-light.h constantes.h  enregistrement.h monde.h textures.h 
SRC = main.c sdl2-light.c monde.c textures.c 
OBJ = $(SRC:%.c=%.o)


INC_TEST = sdl2-light.h monde.h constantes.h enregistrement.h  
SRC_TEST = sdl2-light.c tests.c monde.c
OBJ_TEST = $(SRCTEST:%.c=%.o)

PROG = spacecorridor.exe

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<  -I $(SDL2_INCLUDE_DIR)

$(PROG): $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@ -L $(SDL2_LIBRARIES_DIR)

doc: $(PROG)
	doxygen $(PROG)

tests: $(OBJ_TEST)
	gcc $(CFLAGS) $(OBJ_TEST) $(LDFLAGS) -o $@ -L $(SDL2_LIBRARIES_DIR)

.PHONY: clean
clean:
	del /f /q *.o *~ $(PROG)
	rd /s /q latex html





