/**
* \file tests.c
* \brief Tests des fonctions qui traitent les donnees du monde
* \author AIT OUALI Marouane
* \date 16 avril 2021
*/




#include <stdio.h>
#include <stdlib.h>
#include "monde.h"


void init_sprite_param(sprite_t *sprite, int x, int y, int w, int h){
	init_sprite(sprite, x, y, w, h);
	print_sprite(sprite);
}

void test_init_sprite(){
	sprite_t sprite1;
	sprite_t sprite2;
	sprite_t sprite3;
	init_sprite_param(&(sprite1), 12, 14, 36, 36);
	init_sprite_param(&(sprite2), 0, 0, 0, 0);
	init_sprite_param(&(sprite3), -5, 107, 15, 93);
}


int main(int argc, char **argv){
	test_init_sprite();
	return EXIT_SUCCESS;
}