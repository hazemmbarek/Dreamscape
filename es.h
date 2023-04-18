#ifndef FONCTION_H
#define FONCTION_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1080
#define SCREEN_W 1920
typedef struct
{
char *url;
SDL_Rect pos_img_affiche[3]; 
SDL_Rect pos_img_ecran[3];
SDL_Surface *img;
int state;
}image;

typedef struct enemie
	{ 
            SDL_Surface *spritesheet;  
            SDL_Rect pos,posframe;
            int direction; /*!< Direction*/ 
            SDL_Rect posmin,posmax;
            int frame; /*!< Frame*/ 
     }enemie;

void initialiser_imageBACK(image *imge);
void afficher_imageBACK(SDL_Surface *screen,image imge);
void liberer_image(image imge);
void initennemi(enemie*e)  ;
void afficherennemi(enemie *e, SDL_Surface * screen) ;
void animerennemi( enemie * e)  ;  
void deplacer( enemie * e)  ;  
/*int collisionbb(SDL_Rect E, SDL_Rect p) ;

void moveIA(enemie * E, SDL_Rect posPerso);
*/

#endif
