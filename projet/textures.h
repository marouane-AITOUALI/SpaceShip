/**
* \file textures.h
* \brief en-tête pour la gestion des données graphiques et des textures
* \author AIT OUALI Marouane
* \date 13 avril 2021
*/

#ifndef TEXTURES_H
#define TEXTURES_H

#include "enregistrement.h"
#include <SDL.h>





/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures);




/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world);

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/

void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);


/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void  init_textures(SDL_Renderer *renderer, textures_t *textures);


/**
* \brief la fonction applique la texture sur le renderer dans la position donnée
* \param renderer qui va recevoir la texture
* \param texture la texture que l'on va appliquer
* \param x l'abscisse où on va appliqueer la texture
* \param y l'ordonnée où on va appliquer la texture
*/

void apply_sprite1(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);


/**
* \brief la fonction applique chaque mur à sa position dans le renderer
* \param renderer le renderer
* \param world les données du monde
* \param textures la texture liée au mur
*/

void apply_walls(SDL_Renderer *renderer, world_t *world,textures_t *textures);


/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);

/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);


#endif