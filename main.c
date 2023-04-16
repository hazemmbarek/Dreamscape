#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

int main()
{
SDL_Surface *screen;
image IMAGE, IMAGE_BTN1, IMAGE_BTN2,IMAGE_BTN3,IMAGE_BTN4,imge;
Mix_Music *music;
Mix_Chunk * mus;
texte txte;

SDL_Event event;
int boucle=1;
int k=0;
int isfullscreen=0;
int backgIndex=1;
char imagename[60];

 
if (SDL_Init (SDL_INIT_VIDEO| SDL_INIT_AUDIO|SDL_INIT_TIMER)==1)

{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}

screen=SDL_SetVideoMode(1550, 872, 32,SDL_SWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("GAME", NULL);
//********************custom cursor******************************************************************************************************
/*
SDL_Surface* cursor_img = IMG_Load("/home/hazem/Desktop/4584979.png");
Uint32 rmask, gmask, bmask, amask;

// Get the pixel format of the surface
SDL_PixelFormat* fmt =cursor_img->format;
// Get the bit masks for the color channels
rmask = fmt->Rmask;
gmask = fmt->Gmask;
bmask = fmt->Bmask;
amask = fmt->Amask;
SDL_Surface* cursor_surf = SDL_CreateRGBSurface(0, cursor_img->w, cursor_img->h, 32, rmask, gmask, bmask, amask);
SDL_BlitSurface(cursor_img, NULL, cursor_surf, NULL);

SDL_SetColorKey(cursor_surf, SDL_SRCCOLORKEY, SDL_MapRGB(cursor_surf->format, 0, 0, 0));
SDL_Cursor* cursor = SDL_CreateCursor(cursor_surf->pixels, cursor_surf->pixels, cursor_surf->w, cursor_surf->h, 0, 0);
SDL_SetCursor(cursor);
if(cursor_img == NULL){
printf("unable to load cursor image %s \n",SDL_GetError());
return -1;}
*/
//***************************************************************************************************************************************
initialiser_imageBACK(&IMAGE,"/home/hazem/Desktop/main background/Menu Game 1.png");
initialiser_imageBOUTON1(&IMAGE_BTN1);
initialiser_imageBOUTON2(&IMAGE_BTN2);
initialiser_imageBOUTON3(&IMAGE_BTN3);
initialiser_imageBOUTON4(&IMAGE_BTN4);
initialiser_audio(music);
initialiser_texte(&txte);

while(boucle)
{
if(backgIndex!=0)
{
sprintf(imagename,"/home/hazem/Desktop/main background/Menu Game %d.png",backgIndex);  
afficher_imageBMP(screen,IMAGE);   
IMAGE.img=IMG_Load(imagename);         
SDL_Delay(5);
}
//********************
IMAGE_BTN1.state=0;
IMAGE_BTN2.state=0;
IMAGE_BTN3.state=0;
IMAGE_BTN4.state=0;
afficher_imageBTN2(screen,IMAGE_BTN2);
afficher_imageBTN3(screen,IMAGE_BTN3);
afficher_imageBTN4(screen,IMAGE_BTN4);
afficher_imageBTN1(screen,IMAGE_BTN1);
afficher_texte(screen,txte);
//********************
backgIndex++;
if (backgIndex > 28) 
{
    backgIndex = 1;
}
int x, y;
SDL_GetMouseState(&x, &y);
 

if(y<=IMAGE_BTN1.pos_img_ecran[0].y+37 && y>=IMAGE_BTN1.pos_img_ecran[0].y &&( x<=IMAGE_BTN1.pos_img_ecran[0].x+450&& x>=IMAGE_BTN1.pos_img_ecran[0].x)) 

{IMAGE_BTN1.state=1;
//initialiser_audiobref(mus);
//(SDL_PointInRect(&(m.b), &(IMAGE_BTN1.pos_img_ecran[0]));
SDL_FreeSurface(screen);
afficher_imageBMP(screen,IMAGE);
afficher_imageBTN2(screen,IMAGE_BTN2);
afficher_imageBTN3(screen,IMAGE_BTN3);
afficher_imageBTN4(screen,IMAGE_BTN4);
afficher_imageBTN1(screen,IMAGE_BTN1);
afficher_texte(screen,txte);
}








else if(y<=IMAGE_BTN2.pos_img_ecran[0].y+50 && y>=IMAGE_BTN2.pos_img_ecran[0].y &&( x<=IMAGE_BTN2.pos_img_ecran[0].x+450 && x>=IMAGE_BTN2.pos_img_ecran[0].x))
{IMAGE_BTN2.state=1;


afficher_imageBMP(screen,IMAGE);
afficher_imageBTN2(screen,IMAGE_BTN2);
afficher_imageBTN3(screen,IMAGE_BTN3);
afficher_imageBTN4(screen,IMAGE_BTN4);
afficher_imageBTN1(screen,IMAGE_BTN1);
afficher_texte(screen,txte);}


else if(y<=IMAGE_BTN3.pos_img_ecran[0].y+44&& y>=IMAGE_BTN3.pos_img_ecran[0].y &&( x<=IMAGE_BTN3.pos_img_ecran[0].x+450&& x>=IMAGE_BTN3.pos_img_ecran[0].x))
{IMAGE_BTN3.state=1;


afficher_imageBMP(screen,IMAGE);
afficher_imageBTN2(screen,IMAGE_BTN2);
afficher_imageBTN3(screen,IMAGE_BTN3);
afficher_imageBTN4(screen,IMAGE_BTN4);
afficher_imageBTN1(screen,IMAGE_BTN1);
afficher_texte(screen,txte);}


else if(y<=IMAGE_BTN4.pos_img_ecran[0].y+44 && y>=IMAGE_BTN4.pos_img_ecran[0].y &&( x<=IMAGE_BTN4.pos_img_ecran[0].x+450&& x>=IMAGE_BTN4.pos_img_ecran[0].x+5))
{IMAGE_BTN4.state=1;


afficher_imageBMP(screen,IMAGE);
afficher_imageBTN2(screen,IMAGE_BTN2);
afficher_imageBTN3(screen,IMAGE_BTN3);
afficher_imageBTN4(screen,IMAGE_BTN4);
afficher_imageBTN1(screen,IMAGE_BTN1);
afficher_texte(screen,txte);}




while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_d:
				switch(k)
				{
				case 0:IMAGE_BTN1.state=2;
				
				break;
				case 1:IMAGE_BTN2.state=2;
				break;
				case 2:IMAGE_BTN3.state=2;
				break;
				case 3:IMAGE_BTN4.state=2;
				}
				initialiser_audiobref(mus);
				afficher_imageBMP(screen,IMAGE);
				afficher_imageBTN2(screen,IMAGE_BTN2);
				afficher_imageBTN3(screen,IMAGE_BTN3);
				afficher_imageBTN4(screen,IMAGE_BTN4);
				afficher_imageBTN1(screen,IMAGE_BTN1);
				afficher_texte(screen,txte);
				SDL_Delay(5);
				if(k==1)
					afficherOptionsScreen(screen);
				if(k==0)
					afficherPlayScreen(screen,mus);
				if(k==2)
					afficherCreditsScreen(screen,mus);
				if(k==3)
					boucle=0;
				break;
				
				case SDLK_q:
				IMAGE_BTN4.state=2;
				afficher_imageBMP(screen,IMAGE);
				afficher_imageBTN4(screen,IMAGE_BTN4);
				afficher_imageBTN2(screen,IMAGE_BTN2);
				afficher_imageBTN3(screen,IMAGE_BTN3);
				
				afficher_imageBTN1(screen,IMAGE_BTN1);
				afficher_texte(screen,txte);
				initialiser_audiobref(mus);
				boucle=0;
				break;
				case SDLK_p:
				afficherPlayScreen(screen,mus);
				
				break;
				case SDLK_o:
				IMAGE_BTN2.state=2;
				initialiser_audiobref(mus);
				afficher_imageBMP(screen,IMAGE);
				afficher_imageBTN2(screen,IMAGE_BTN2);
				afficher_imageBTN3(screen,IMAGE_BTN3);
				afficher_imageBTN4(screen,IMAGE_BTN4);
				afficher_imageBTN1(screen,IMAGE_BTN1);
				afficher_texte(screen,txte);
				break;
				case SDLK_DOWN:
				k++;
				if(k<0)
				k=3;
				if(k>3)
				k=0;
				switch(k)
				{
				case 0:IMAGE_BTN1.state=1;
				break;
				case 1:IMAGE_BTN2.state=1;
				break;
				case 2:IMAGE_BTN3.state=1;
				break;
				case 3:IMAGE_BTN4.state=1;
				break;
				}
				initialiser_audiobref(mus);
				afficher_imageBMP(screen,IMAGE);
				afficher_imageBTN2(screen,IMAGE_BTN2);
				afficher_imageBTN3(screen,IMAGE_BTN3);
				afficher_imageBTN4(screen,IMAGE_BTN4);
				afficher_imageBTN1(screen,IMAGE_BTN1);
				afficher_texte(screen,txte);
				
				break;
				case SDLK_UP:
				k--;
				if(k<0)
				k=3;
				if(k>3)
				k=0;
				switch(k)
				{
				case 0:IMAGE_BTN1.state=1;
				break;
				case 1:IMAGE_BTN2.state=1;
				break;
				case 2:IMAGE_BTN3.state=1;
				break;
				case 3:IMAGE_BTN4.state=1;
				break;
				}
				initialiser_audiobref(mus);
				afficher_imageBMP(screen,IMAGE);
				afficher_imageBTN2(screen,IMAGE_BTN2);
				afficher_imageBTN3(screen,IMAGE_BTN3);
				afficher_imageBTN4(screen,IMAGE_BTN4);
				afficher_imageBTN1(screen,IMAGE_BTN1);
				afficher_texte(screen,txte);
				break;;
				
	
			}



		case SDL_MOUSEBUTTONDOWN:
		if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=IMAGE_BTN1.pos_img_ecran[IMAGE_BTN1.state].y+38 && 		event.button.y>=IMAGE_BTN1.pos_img_ecran[IMAGE_BTN1.state].y &&( event.button.x<=IMAGE_BTN1.pos_img_ecran[IMAGE_BTN1.state].x+440&& event.button.x>=IMAGE_BTN1.pos_img_ecran[IMAGE_BTN1.state].x)))
		
		{
		IMAGE_BTN1.state=2;
		afficher_imageBMP(screen,IMAGE);
		afficher_imageBTN2(screen,IMAGE_BTN2);
		afficher_imageBTN3(screen,IMAGE_BTN3);
		afficher_imageBTN4(screen,IMAGE_BTN4);
		afficher_imageBTN1(screen,IMAGE_BTN1);
		afficher_texte(screen,txte);
		initialiser_audiobref(mus);
		afficherPlayScreen(screen,mus);
		}
				 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=IMAGE_BTN2.pos_img_ecran[IMAGE_BTN2.state].y+50 && 		event.button.y>=IMAGE_BTN2.pos_img_ecran[IMAGE_BTN2.state].y &&( event.button.x<=IMAGE_BTN2.pos_img_ecran[IMAGE_BTN2.state].x+590&& event.button.x>=IMAGE_BTN2.pos_img_ecran[IMAGE_BTN2.state].x)))
		
		{
		IMAGE_BTN2.state=2;
		afficher_imageBMP(screen,IMAGE);
		afficher_imageBTN2(screen,IMAGE_BTN2);
		afficher_imageBTN3(screen,IMAGE_BTN3);
		afficher_imageBTN4(screen,IMAGE_BTN4);
		afficher_imageBTN1(screen,IMAGE_BTN1);
		afficher_texte(screen,txte);
		initialiser_audiobref(mus);
		afficherOptionsScreen(screen);
		}
					else if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=IMAGE_BTN3.pos_img_ecran[IMAGE_BTN3.state].y+50 && 		event.button.y>=IMAGE_BTN3.pos_img_ecran[IMAGE_BTN3.state].y &&( event.button.x<=IMAGE_BTN3.pos_img_ecran[IMAGE_BTN3.state].x+590&& event.button.x>=IMAGE_BTN3.pos_img_ecran[IMAGE_BTN3.state].x)))
		
		{
		IMAGE_BTN3.state=2;
		afficher_imageBMP(screen,IMAGE);
		afficher_imageBTN2(screen,IMAGE_BTN2);
		afficher_imageBTN3(screen,IMAGE_BTN3);
		afficher_imageBTN4(screen,IMAGE_BTN4);
		afficher_imageBTN1(screen,IMAGE_BTN1);
		afficher_texte(screen,txte);
		initialiser_audiobref(mus);
		afficherCreditsScreen(screen,mus);
		
		}
					else if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].y+50 && 		event.button.y>=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].y+8 &&( event.button.x<=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].x+440&& event.button.x>=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].x)))
		
		{
		IMAGE_BTN4.state=2;
		afficher_imageBMP(screen,IMAGE);
		afficher_imageBTN4(screen,IMAGE_BTN4);
		afficher_imageBTN2(screen,IMAGE_BTN2);
		afficher_imageBTN3(screen,IMAGE_BTN3);
		
		afficher_imageBTN1(screen,IMAGE_BTN1);
		afficher_texte(screen,txte);
		initialiser_audiobref(mus);
		boucle=0;
		}
		break;
		



/*case SDL_MOUSEMOTION:
		if(event.motion.y<=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].y+100 && event.motion.y>=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].y &&( event.motion.x<=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].x+320&& event.motion.x>=IMAGE_BTN4.pos_img_ecran[IMAGE_BTN4.state].x))
{IMAGE_BTN4.state=2;
		afficher_imageBMP(screen,IMAGE);
		afficher_imageBTN4(screen,IMAGE_BTN4);
		afficher_imageBTN2(screen,IMAGE_BTN2);
		afficher_imageBTN3(screen,IMAGE_BTN3);
		
		afficher_imageBTN1(screen,IMAGE_BTN1);
		afficher_texte(screen,txte);}		
break;*/
	

}
}
SDL_Flip(screen);

}

liberer_image(IMAGE);
liberer_image(IMAGE_BTN1);
liberer_image(IMAGE_BTN2);
liberer_musique(music);
//liberer_musiquebref(mus);
Liberer_texte(txte);
//*****************************************
 /*  SDL_FreeCursor(cursor);
    SDL_FreeSurface(cursor_surf);
    SDL_FreeSurface(cursor_img);*/
//*****************************************
TTF_Quit();
SDL_Quit();
return 0;
}
