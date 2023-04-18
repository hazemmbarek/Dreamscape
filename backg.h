#ifndef BACKG_H
#define BACKG_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_WIDTH 1550
#define SCREEN_HEIGHT 880
#define BPP 32


 
typedef struct
{
SDL_Rect pos,splitposscreen;
SDL_Surface *img1;
SDL_Surface *img2;
SDL_Surface *img3;
int level,anim,splitscreen,player;
}background;


typedef struct
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}texte;

 

void initBackg(background *b);
void afficherBack(background b,SDL_Surface *screen,SDL_Rect pos2);
void animerBack(background *b);
void scrolling(background *b,int direction,SDL_Rect *pos2);

#endif
