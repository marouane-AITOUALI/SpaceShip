/**
* \file monde.h
* \brief en-tête pour la gestion des données logiques du monde
* \author AIT OUALI Marouane
* \date 13 avril 2021
*/

#ifndef MONDE_H
#define MONDE_H

#include "enr.h"




/*
* \brief fonction qui affiche les informations du sprite 
* \param sprite l element representant un vaisseau
*/

void print_sprite(sprite_t *sprite);


/**
* \brief fonction qui initialise les coordonnées du vaisseau
* \param sprite le vaisseau
* \param x, y, w, h coordonnées du vaisseau
*/

void init_sprite(sprite_t *sprite, int x, int y, int w, int h);


/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */

void init_data(world_t * world);


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world);


/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

void handle_events(SDL_Event *event,world_t *world);


/**
* \brief la fonction qui applique une texture sur le renderer a la position dans le sprite
* \param renderer qui va recevoir la texture
* \param texture la texture que l'on va appliquer
* \param sprite structure sprite contenant ses coordonnées
*/

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);


/**
* \brief la fonction qui verifie si le vaisseau depasse la limite gauche de l'ecran
* \param sprite qui represente le vaisseau
*/

void depasse_gauche(sprite_t *sprite);


/**
* \brief la fonction qui verifie si le vaisseau depasse la limite droite de l'ecran
* \param sprite qui represente le vaisseau
*/

void depasse_droite(sprite_t *sprite);


/**
* \brief fonction qui verifie si deux sprites sont en collisions
* \param sp1 represente le premier sprite
* \param sp2 represente le deuxieme sprite
* \return retourne 1 en cas de collision, 0 sinon
*/

int sprites_collide(sprite_t *sp1, sprite_t *sp2);


/**
* \brief fonction qui arrete le defilement vertical des donnees du monde en cas de collision
* \param sp1 represente un premier sprite
* \param sp2 represente un deuxieme sprite
* \param world les donnees du monde
* \param make_disappear rend le premier sprite sp1 invisible si ce parametre est different de 0
*/

void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world, int make_disappear);


/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world);





#endif
