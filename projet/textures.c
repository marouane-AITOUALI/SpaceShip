/**
* \file textures.c
* \brief en-tête pour la gestion des données graphiques et des textures
* \author AIT OUALI Marouane
* \date 13 avril 2021
*/

#include "textures.h"
#include "enr.h"
#include "constantes.h"
#include "sdl2-light.h"






void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
  apply_texture(texture, renderer, sprite->x, sprite->y);
}

void apply_sprite1(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y){ // je les crée pour les murs de meteorites
  apply_texture(texture, renderer, x, y);
}

void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp", renderer);
    textures->sprite = load_image("ressources/spaceship.bmp", renderer);
    textures->ligneArrive = load_image("ressources/finish_line.bmp", renderer);
    textures->meteore = load_image("ressources/meteorite.bmp", renderer);
}

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->sprite);
    clean_texture(textures->ligneArrive);
    clean_texture(textures->meteore);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    
    //application des textures dans le renderer
    apply_background(renderer, textures->background);
    apply_sprite(renderer, textures->sprite, &(world->sprite));
    apply_sprite(renderer, textures->ligneArrive, &(world->ligneArrive));

    // application des textures de la meteorite dans les endroits spécifiques
    apply_sprite(renderer, textures->meteore, &(world->meteore)); // centre
    apply_sprite1(renderer, textures->meteore, world->meteore.x + METEORITE_SIZE, world->meteore.y); // à droite du centre
    apply_sprite1(renderer, textures->meteore, world->meteore.x - METEORITE_SIZE, world->meteore.y); // à gauche du centre
    for (int i = 1; i <=3; i++){
      /* Les meteores de la ligne centrale */
      apply_sprite1(renderer, textures->meteore, world->meteore.x, world->meteore.y + (i * METEORITE_SIZE));
      apply_sprite1(renderer, textures->meteore, world->meteore.x, world->meteore.y - (i * METEORITE_SIZE));
      /*Les meteores à gauche de la ligne centrale */
      apply_sprite1(renderer, textures->meteore, world->meteore.x -  METEORITE_SIZE, world->meteore.y + (i * METEORITE_SIZE));
      apply_sprite1(renderer, textures->meteore, world->meteore.x - METEORITE_SIZE, world->meteore.y - (i * METEORITE_SIZE));
      /*Les meteores à droite de la ligne centrale */
      apply_sprite1(renderer, textures->meteore, world->meteore.x + METEORITE_SIZE, world->meteore.y + (i * METEORITE_SIZE));
      apply_sprite1(renderer, textures->meteore, world->meteore.x + METEORITE_SIZE, world->meteore.y - (i * METEORITE_SIZE));

    }
    
    // on met à jour l'écran
    update_screen(renderer);
}

void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}




