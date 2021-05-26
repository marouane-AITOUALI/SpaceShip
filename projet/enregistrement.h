/**
* \file enre.h
* \brief Enregistrements
* \author AIT OUALI Marouane
* \date 13 avril 2021
*/

#ifndef ENR_H
#define ENR_H

#include <SDL.h>

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* sprite;     // texture liée au vaisseu
    SDL_Texture* ligneArrive; 
    SDL_Texture* meteore;
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;

/**
* \brief Representation du vaisseau
* \param (x,y) les coordonnées
* \param h&w : hauteur et largeur 
*/

struct sprite_s{
  int x;
  int y;
  int h;
  int w;
};

typedef struct sprite_s sprite_t;

/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
    sprite_t sprite; // Champ pour le vaisseau
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    sprite_t ligneArrive; // Champ concernant la ligne d'arrivée
    int vy; // vitesse verticale de la ligne d'arrivée
    //sprite_t meteore;
    sprite_t murs[58];

};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;



#endif