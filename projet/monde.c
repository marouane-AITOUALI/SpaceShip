/**
* \file monde.c
* \brief Implantation pour la gestion des données du monde
* \author AIT OUALI Marouane
* \date 13 avril 2021
*/

#include "monde.h"
#include "enr.h"
#include "constantes.h"
#include "sdl2-light.h"
#include <stdio.h>
#include <stdlib.h>


void print_sprite(sprite_t *sprite){
  printf("Les coordonnées du sprite sont: (%d,%d)\n", sprite->x, sprite->y);
  printf("La largeur du sprite: %d\n", sprite->w);
  printf("La hauteur du sprite: %d\n", sprite->h);
}


void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
  sprite->x = x;
  sprite->y = y;
  sprite->w = w;
  sprite->h = h;
}



void init_data(world_t * world){
    
    //on n'est pas à la fin du jeu
    world->gameover = 0;

    // On initialise la vitesse verticale
    world->vy = INITIAL_SPEED;
    // On initialise les données du vaisseau
    init_sprite(&(world->sprite), SCREEN_WIDTH / 2,  SCREEN_HEIGHT - (1.5 * SHIP_SIZE), SHIP_SIZE, SHIP_SIZE);
    
    // On initialise les données de la ligne d'arrivée
    init_sprite(&(world->ligneArrive), 0, FINISH_LINE_HEIGHT + (FINISH_LINE_HEIGHT / 2), SCREEN_WIDTH, FINISH_LINE_HEIGHT);
    
    // On initialise les données du meteorite 
    init_sprite(&(world->meteore), (SCREEN_WIDTH - METEORITE_SIZE) / 2, (SCREEN_HEIGHT - METEORITE_SIZE) / 2, 3 * METEORITE_SIZE, 7 * METEORITE_SIZE);

    // On affiche les données du vaisseau
    print_sprite(&(world->sprite));                   
    
}


void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1;
        }
       
         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){
             //si la touche appuyée est 'D'
             if(event->key.keysym.sym == SDLK_d){
                 printf("La touche D est appuyée\n");
                 world->gameover = 1;
              }

              else if(event->key.keysym.sym == SDLK_RIGHT){
                world->sprite.x += MOVING_STEP;
                print_sprite(&(world->sprite));
              }

              else if(event->key.keysym.sym == SDLK_LEFT){
                world->sprite.x -= MOVING_STEP;
                print_sprite(&(world->sprite));
              }

              else if(event->key.keysym.sym == SDLK_UP){
                world->vy += 1;
              }

              else if(event->key.keysym.sym == SDLK_DOWN){
                world->vy -= 1;
              }

              else if(event->key.keysym.sym == SDLK_ESCAPE){
                printf("La touche Echape est appuyée\n");
                world->gameover = 1;
              }
         }
    }
}

void depasse_gauche(sprite_t *sprite){
  if (sprite->x < SHIP_SIZE/2){
    sprite->x = SHIP_SIZE/2;
  }
}

void depasse_droite(sprite_t *sprite){
  if (sprite->x > SCREEN_WIDTH - (1.5*SHIP_SIZE)){
    sprite->x = SCREEN_WIDTH - 1.5*SHIP_SIZE;
  }
}

int sprites_collide(sprite_t *sp1, sprite_t *sp2){
  if ((abs(sp1->x - sp2->x) <= (sp1->w + sp2->w) / 2) && (abs(sp1->y - sp2->y) <= (sp1->h + sp2->h)/2)) {
    return 1;
  }
  return 0;

}

void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world, int make_disappear){
  if (sprites_collide(sp1, sp2)){
    world->vy = 0; // Collision donc on arrete le defilement des donnees du monde
    if (make_disappear != 0){
      init_sprite(sp1, -50, -50, 0, 0); // en place le vaisseau en dehors de l'ecran pour qu'il disparait 
    }
  }
}

void update_data(world_t *world){
    world->ligneArrive.y += world->vy;
    world->meteore.y += world->vy;
    depasse_gauche(&(world->sprite));
    depasse_droite(&(world->sprite));
    handle_sprites_collision(&(world->sprite), &(world->meteore), world, 1); /* Changer le 1 par 0
    pour que le vaisseau ne devient plus invisible en cas de collision */
    handle_sprites_collision(&(world->sprite), &(world->ligneArrive), world, 0);
}


int is_game_over(world_t *world){
    return world->gameover;
}
