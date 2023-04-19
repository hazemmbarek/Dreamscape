#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "es.h"


void initennemi(enemie*e)
 {
    e->spritesheet=IMG_Load("/home/tek/Desktop/222/Sans titredd-111111111111111111111111111111111111.png");
    e->frame=0;// l'ennemi commencera avec la première frame de sa spritesheet.
    e->direction=0; 
    e->pos.x=535;//pos d'affichage en x
    e->pos.y=360;//pos d'affichage en y
    e->posframe.x=0;//pos sprite sheet init en 1ere pos en y
    e->posframe.y=250;//pos sprite sheet init en 1ere pos en y
    e->posframe.h=280;//pos sprite sheet init en 1ere pos en h
    e->posframe.w=265;//pos sprite sheet init en 1ere pos en w
    //e->posmax.x=1150;//pos max en x
 //   e->posmin.x=0;//pos min en x

}


void afficherennemi(enemie *e, SDL_Surface * screen) {

 SDL_BlitSurface(e->spritesheet,&e->posframe,screen,&e->pos);
}

void animerennemi( enemie * e) {
    
	if(e->posframe.x < 760){
    e->posframe.x = e->posframe.x + e->posframe.w;
    }
        else 
	//e->posframe.y = e->direction *  e->posframe.h ;
e->posframe.x=0;
    
    
} 


void deplacer(enemie *e)
{
int posMax=0,posMin=0;
posMax=900;
posMin=50;
if (e->direction==0)
    {
        e->pos.x += 8;
    }else if (e->direction==1)
    {
        e->pos.x -= 8;
    }

    if (e->pos.x > posMax)
    {
        e->direction=1;
    }
    if (e->pos.x < posMin)
    {
        e->direction=0;
}}
int collisionbb(SDL_Rect E, SDL_Rect p)
 {
  int collision,px,py;
  px=p.x+100;
  py=p.y+120;
  if (((px + p.w) < E.x) || (px > (E.x + E.w)) || ((py + p.h) < E.y) || (py > (E.y + E.h))) 
  {
    collision = 0;
  } else {
    collision = 1;
  }

  return collision;
}

void moveIA(enemie * e, SDL_Rect posPerso) {
printf("posennn :%d\n",e -> pos.x - posPerso.x);
printf("posx:%d\n",e-> pos.x);
//printf("posperso:%d\n",posPerso);
  if (((e -> pos.x - posPerso.x) < val) && ((e -> pos.x - posPerso.x) > val))  
   {
    e -> direction = 1; ///gauche
    e -> pos.x -= 8;
  } 
  else if (((e -> pos.x - posPerso.x) < val) && ((e -> pos.x - posPerso.x) > -val))
   {
    e -> direction = 0; //droite
    e -> pos.x += 8;
  } 
  else if (((e -> pos.x - posPerso.x) <=val) && ((e -> pos.x - posPerso.x) >= val)) 
  {
    e -> direction = 2;//droite fire
  } 
  else if (((e -> pos.x - posPerso.x) <= val) && ((e -> pos.x - posPerso.x) >= val)) 
  {
    e -> direction = 3;//gauche fire
    
  }
  else deplacer(e);

}
}

/********************************************BACKGROUND**************************************************************************************/
void initialiser_imageBACK(image *imge) 
{
	imge->url="/home/tek/Desktop/testttt/wallpapersden.com_lakeside-hd-pixel-art_1920x1080.jpg";
	imge->img=IMG_Load(imge->url);

if (imge->img == NULL) {
printf ("unable to load background image %s \n",SDL_GetError());
return ;}
imge->pos_img_ecran[0].x=0;
imge->pos_img_ecran[0].y=0;
imge->pos_img_affiche[0].x=0;
imge->pos_img_affiche[0].y=0;
imge->pos_img_affiche[0].h=1080;
imge->pos_img_affiche[0].w=1920;
}


void afficher_imageBACK(SDL_Surface *screen,image imge)
{
imge.state=0;
SDL_BlitSurface(imge.img, &(imge.pos_img_affiche[0]), screen, &(imge.pos_img_ecran[0])) ;
}
void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}
