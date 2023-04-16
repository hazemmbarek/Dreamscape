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

SDL_Rect srcrect;
SDL_Rect dstrect;

typedef struct
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}texte;

typedef struct
{
int score;
int time;
char playername[20];
}scoreinfo;
 
void saveScore(scoreinfo s,char *filename);
void bestScore(char *filename,scoreinfo tscore[],SDL_Surface *screen);

void afficherPlayScreen(SDL_Surface* screen,Mix_Chunk * mus);
void initialiser_imageBOUTON1 (image *imgbtn);
void initialiser_imageBOUTON2 (image *imgbtn);
void initialiser_imageBOUTON3(image *imgbtn);
void initialiser_imageBOUTON4(image *imgbtn);
void afficher_imageBMP(SDL_Surface *screen, image imge);
void afficher_imageBTN1(SDL_Surface *screen, image imge);
void afficher_imageBTN2(SDL_Surface *screen, image imge);
void afficher_imageBTN3(SDL_Surface *screen, image imge);
void afficher_imageBTN4(SDL_Surface *screen, image imge);
void liberer_image(image imge);
void initialiser_imageBACK1(image *imge);
void afficher_imageBMP1(SDL_Surface *screen,image imge);
void afficherCreditsScreen(SDL_Surface* screen,Mix_Chunk * mus);
void initialiser_audio(Mix_Music *music);
void liberer_musique (Mix_Music *music);
void initialiser_imageBACK(image *imge,char *url);
void initialiser_audiobref (Mix_Chunk *mus);
void liberer_musiquebref (Mix_Chunk *mus);

void liberer_audiobref(Mix_Chunk *mus); 

void initialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen, texte txte);
void Liberer_texte(texte txte);
void afficherOptionsScreen(SDL_Surface* screen);
#endif
