#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"

void initBackg(background *b)
{	
if(b->splitscreen==0)
  {
	if(b->level==1)
	{
    b->pos.x=0;
    b->pos.y=50;
    b->pos.h=880;
    b->pos.w=1550;
    
 
    b->img1 = IMG_Load("/home/hazem/Desktop/BACKG/wallpapersden.com_lakeside-hd-pixel-art_1920x1080.jpg");
    b->img2 = IMG_Load("/home/hazem/Desktop/wallpapersden.com_landscape-pixel-art_1920x1080.jpg");
    if (b->img1 == NULL)
    {
        fprintf(stderr, "Error loading background image: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
	}
   } 
   if(b->splitscreen==1)
 {
    
	if(b->level==1)
	{
    b->pos.x=0;
    b->pos.y=50;
    b->pos.h=880;
    b->pos.w=775;
    b->splitposscreen.x=775;
    b->splitposscreen.y=0;
    
    b->img1 = IMG_Load("/home/hazem/Desktop/BACKG/wallpapersden.com_lakeside-hd-pixel-art_1920x1080.jpg");
    b->img2 = IMG_Load("/home/hazem/Desktop/wallpapersden.com_landscape-pixel-art_1920x1080.jpg");
    if (b->img1 == NULL)
    {
        fprintf(stderr, "Error loading background image: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
	}
 }

    
}

void afficherBack(background b,SDL_Surface *screen,SDL_Rect pos2)
{
	if(b.splitscreen==0)
  {
	if(b.level==1)
	{
	   	if(b.anim==0)
    		{
			SDL_BlitSurface(b.img1,&b.pos, screen, NULL);
    		}
		else
			SDL_BlitSurface(b.img2,&b.pos, screen, NULL);
	}
   }
   if(b.splitscreen==1)
  {
	if(b.level==1)
	{
	   	if(b.anim==0)
    		{
			SDL_BlitSurface(b.img1,&b.pos, screen, NULL);
			SDL_BlitSurface(b.img1,&pos2, screen,&b.splitposscreen);
    		}
		else
		{	
			SDL_BlitSurface(b.img2,&b.pos, screen, NULL);
			SDL_BlitSurface(b.img2,&pos2, screen,&b.splitposscreen);
		}
	}
  }
}
void animerBack(background *b)
{
	b->anim++;
	if((b->anim<0)||(b->anim>2))
		{
			b->anim=0;
		}
	
}
void scrolling(background *b,int direction,SDL_Rect *pos2)
{
   
	if (direction==1)
	{
		if(b->player==1)
		{
		    b->pos.x=b->pos.x+10;
			if(b->pos.x>30)
				b->pos.x=30;
                }
		if(b->player==2)
		{
		    pos2->x=pos2->x+10;
			if(pos2->x>30)
				pos2->x=30;
                }
	}
	else if (direction==2)
	{
		if(b->player==1)
		{
		b->pos.x=b->pos.x-10;
			if(b->pos.x<0)
				b->pos.x=0;
		}
		if(b->player==2)
		{
		pos2->x=pos2->x-10;
			if(pos2->x<0)
				pos2->x=0;
		}
	}
	else if (direction==3)
	{
		if(b->player==1)
		{
		b->pos.y=b->pos.y-10;
			if(b->pos.y<0)
				b->pos.y=0;
		}
		if(b->player==2)
		{
		pos2->y=pos2->y-10;
			if(pos2->y<0)
				pos2->y=0;
		}
	}
	else
	{
		if(b->player==1)
		{
		b->pos.y=b->pos.y+10;
			if(b->pos.y>40)
				b->pos.y=40;
		}
		if(b->player==2)
		{
		pos2->y=pos2->y+10;
			if(pos2->y>40)
				pos2->y=40;
		}
	}

     
}
