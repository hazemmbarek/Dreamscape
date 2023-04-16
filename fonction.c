#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


void saveScore(scoreinfo s,char *filename)
{
	FILE *f=NULL;
	f=fopen(filename,"a");
	if(f!=NULL)
	{
	   
		fprintf(f," %s %d %d\n",s.playername,s.score,s.time);
		fclose(f);
	}
}

void bestScore(char *filename,scoreinfo tscore[],SDL_Surface *screen)
{
	FILE *f=NULL;
	texte *scoretxt;
	char texttoprint[100];
	scoreinfo tampon;
	int i=0,j,k,min;
	f=fopen(filename,"r");
	if(f!=NULL)
	{
		 while(!feof(f))
   	        {
		fscanf(f," %s %d %d\n",tscore[i].playername,&tscore[i].score,&tscore[i].time);
		i++;
	        }
		fclose(f);
		int size=i;
		// tri par score
	       for (j=0;j<i-1;j++)
		{
 			min=j;
 		   for (k=j+1;j<i;k++)
    		   {	if (tscore[k].score<tscore[min].score)
       			{min=k;
			tampon=tscore[j];
 			tscore[j]=tscore[min];
 			tscore[min]=tampon;}
		   }
		}



		//declaration tab de tri 2
		scoreinfo tab[size];
		int l,n,rep=1;
		k=0;

		// tri par temps
		for (j=0;j<i;j++)
		{
			if(tscore[j].score!=tscore[j+1].score)
				{
				tab[k]=tscore[j];
				k++;

				for(l=j+1;l<i+1;l++)
				{
					tscore[l-1]=tscore[l];
				}
				j--;
				i--;
				}

			else
			{
				n=j;
				while(tscore[n].score==tscore[n+1].score)
					{
					rep++;
					n++;
					}
				for(n=0;n<0+rep-1;n++)
				{
					min=n;
 		  			for (l=n+1;l<rep;l++)
    		  		 	{			
						if (tscore[l].time<tscore[min].time)
       								{
								min=l;
								tampon=tscore[n];
 								tscore[n]=tscore[min];
 								tscore[min]=tampon;
								}
		  			 }
					tab[k]=tscore[n];
					k++;
				}
				for(n=0;n<rep-1;n++)
				{
					tscore[n]=tscore[n+1];
					
				}
				j=0;
				i=i-rep;
			}
         	}
	//affichage
	j=0;
	for(i=0;i<3;i++)
	{
		
		
		initialiser_texte(scoretxt);	
		scoretxt->pos_txt.x=125;
		scoretxt->pos_txt.y=727+j;	
		sprintf(texttoprint,"%s %d %d secs",tab[i].playername,tab[i].score,tab[i].time);
		scoretxt->txt=TTF_RenderText_Blended(scoretxt->police,texttoprint,scoretxt->color_txt);
		SDL_BlitSurface(scoretxt->txt, NULL, screen, &scoretxt->pos_txt);
		j=j+10;
	}
	}
	free(f);
}







void afficherCreditsScreen(SDL_Surface* screen,Mix_Chunk * mus)
{
	SDL_Event event;
	SDL_Surface	*background = IMG_Load("/home/hazem/Desktop/CONFIG Menu.png");
//*******************************************************
//*******************************************************





	int leave=0;

while (!leave)
{		SDL_BlitSurface(background, NULL, screen, NULL);
		SDL_Flip(screen);
//button hover state
		/*int x, y;
		SDL_GetMouseState(&x, &y);
		volume.state=plus.state=minus.state=mute.state=fullscreen.state=back.state=keybinds.state=on.state=off.state=0;
 

		 if(y<=mute.pos_img_ecran[mute.state].y+36 && y>=mute.pos_img_ecran[mute.state].y &&( x<=mute.pos_img_ecran[mute.state].x+270&& x>=mute.pos_img_ecran[mute.state].x)) 
			{
			mute.state=1;
			}
		else if(y<=on.pos_img_ecran[on.state].y+43 && y>=on.pos_img_ecran[on.state].y &&( x<=on.pos_img_ecran[on.state].x+90&& 	x>=on.pos_img_ecran[on.state].x)) 
		{
				on.state=1;
		}*/
		
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				leave=1;
				break;
			case SDL_KEYDOWN:
		
				if (event.key.keysym.sym == SDLK_b)
				{
					leave=1;
				
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
			/*if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=on.pos_img_ecran[on.state].y+43 && event.button.y>=on.pos_img_ecran[on.state].y &&( event.button.x<=on.pos_img_ecran[on.state].x+230&& event.button.x>=on.pos_img_ecran[on.state].x))&& isfullscreen==0)
			{
					initialiser_audiobref(mus);
                        		screen = SDL_SetVideoMode(1550, 872, 32, SDL_SWSURFACE | SDL_FULLSCREEN|SDL_DOUBLEBUF|SDL_RESIZABLE);
					isfullscreen=1;
					on.state=2;
                       	}*/	
			
			break;

			}
		}	
    }
}
void afficherPlayScreen(SDL_Surface* screen,Mix_Chunk * mus)
{
	SDL_Event event;
	SDL_Surface	*background = IMG_Load("/home/hazem/Desktop/CONFIG Menu.png");
//*******************************************************//
//*******************************************************//





	int leave=0;

while (!leave)
{		SDL_BlitSurface(background, NULL, screen, NULL);
		SDL_Flip(screen);
//button hover state
		/*int x, y;
		SDL_GetMouseState(&x, &y);
		volume.state=plus.state=minus.state=mute.state=fullscreen.state=back.state=keybinds.state=on.state=off.state=0;
 

		 if(y<=mute.pos_img_ecran[mute.state].y+36 && y>=mute.pos_img_ecran[mute.state].y &&( x<=mute.pos_img_ecran[mute.state].x+270&& x>=mute.pos_img_ecran[mute.state].x)) 
			{
			mute.state=1;
			}
		else if(y<=on.pos_img_ecran[on.state].y+43 && y>=on.pos_img_ecran[on.state].y &&( x<=on.pos_img_ecran[on.state].x+90&& 	x>=on.pos_img_ecran[on.state].x)) 
		{
				on.state=1;
		}*/
		
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				leave=1;
				break;
			case SDL_KEYDOWN:
		
				if (event.key.keysym.sym == SDLK_b)
				{
					leave=1;
				
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
			/*if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=on.pos_img_ecran[on.state].y+43 && event.button.y>=on.pos_img_ecran[on.state].y &&( event.button.x<=on.pos_img_ecran[on.state].x+230&& event.button.x>=on.pos_img_ecran[on.state].x))&& isfullscreen==0)
			{
					initialiser_audiobref(mus);
                        		screen = SDL_SetVideoMode(1550, 872, 32, SDL_SWSURFACE | SDL_FULLSCREEN|SDL_DOUBLEBUF|SDL_RESIZABLE);
					isfullscreen=1;
					on.state=2;
                       	}*/	
			
			break;

			}
		}	
    }
}
void afficherOptionsScreen(SDL_Surface* screen)
{
	SDL_Event event;
	scoreinfo s1,s2;
	scoreinfo tscore[20];
	sprintf(s1.playername,"hazem1");
	sprintf(s2.playername,"hazem2");
	s1.score=10;
	s2.score=22;
	s1.time=100;
	s2.time=1233;
	saveScore(s1,"score.txt");
	//saveScore(s2,"score.txt");
	bestScore("score.txt",tscore,screen);
	
	SDL_Surface	*background = IMG_Load("/home/hazem/Desktop/CONFIG Menu.png");
//*******************************************************
//*******************************************************
//initialisation des buttons	
image volume,plus,minus,mute,fullscreen,back,keybinds,on,off;
volume.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(volume.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
volume.pos_img_affiche[0].x=173;
volume.pos_img_affiche[0].y=716;
volume.pos_img_affiche[0].w=450;
volume.pos_img_affiche[0].h=50;
volume.pos_img_ecran[0].x=1180;
volume.pos_img_ecran[0].y=370;
volume.pos_img_ecran[0].w=350;
volume.pos_img_ecran[0].h=53;

//***************************************************************
plus.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(plus.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
plus.pos_img_affiche[0].x=133;
plus.pos_img_affiche[0].y=770;
plus.pos_img_affiche[0].w=150;
plus.pos_img_affiche[0].h=37;
plus.pos_img_ecran[0].x=1430;
plus.pos_img_ecran[0].y=435;
plus.pos_img_ecran[0].w=350;
plus.pos_img_ecran[0].h=53;

plus.pos_img_affiche[1].x=163;
plus.pos_img_affiche[1].y=1100;
plus.pos_img_affiche[1].w=150;
plus.pos_img_affiche[1].h=50;
plus.pos_img_ecran[1].x=1430;
plus.pos_img_ecran[1].y=435;
plus.pos_img_ecran[1].w=350;
plus.pos_img_ecran[1].h=53;

plus.pos_img_affiche[2].x=125;
plus.pos_img_affiche[2].y=1450;
plus.pos_img_affiche[2].w=500;
plus.pos_img_affiche[2].h=55;
plus.pos_img_ecran[2].x=1430;
plus.pos_img_ecran[2].y=435;
plus.pos_img_ecran[2].w=500;
plus.pos_img_ecran[2].h=55;
//***************************************************************
on.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(on.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
on.pos_img_affiche[0].x=123;
on.pos_img_affiche[0].y=1811;
on.pos_img_affiche[0].w=150;
on.pos_img_affiche[0].h=37;
on.pos_img_ecran[0].x=1430;
on.pos_img_ecran[0].y=600;
on.pos_img_ecran[0].w=350;
on.pos_img_ecran[0].h=53;

on.pos_img_affiche[1].x=163;
on.pos_img_affiche[1].y=1860;
on.pos_img_affiche[1].w=150;
on.pos_img_affiche[1].h=50;
on.pos_img_ecran[1].x=1430;
on.pos_img_ecran[1].y=600;
on.pos_img_ecran[1].w=350;
on.pos_img_ecran[1].h=53;

on.pos_img_affiche[2].x=143;
on.pos_img_affiche[2].y=1909;
on.pos_img_affiche[2].w=150;
on.pos_img_affiche[2].h=63;
on.pos_img_ecran[2].x=1430;
on.pos_img_ecran[2].y=600;
on.pos_img_ecran[2].w=350;
on.pos_img_ecran[2].h=53;
//***************************************************************
off.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(off.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
off.pos_img_affiche[0].x=123;
off.pos_img_affiche[0].y=2000;
off.pos_img_affiche[0].w=150;
off.pos_img_affiche[0].h=37;
off.pos_img_ecran[0].x=1230;
off.pos_img_ecran[0].y=600;
off.pos_img_ecran[0].w=350;
off.pos_img_ecran[0].h=53;

off.pos_img_affiche[1].x=123;
off.pos_img_affiche[1].y=2055;
off.pos_img_affiche[1].w=350;
off.pos_img_affiche[1].h=50;
off.pos_img_ecran[1].x=1230;
off.pos_img_ecran[1].y=600;
off.pos_img_ecran[1].w=350;
off.pos_img_ecran[1].h=50;

off.pos_img_affiche[2].x=123;
off.pos_img_affiche[2].y=2120;
off.pos_img_affiche[2].w=350;
off.pos_img_affiche[2].h=60;
off.pos_img_ecran[2].x=1230;
off.pos_img_ecran[2].y=600;
off.pos_img_ecran[2].w=350;
off.pos_img_ecran[2].h=60;
//**************************************************
minus.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(minus.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
minus.pos_img_affiche[0].x=310;
minus.pos_img_affiche[0].y=810;
minus.pos_img_affiche[0].w=450;
minus.pos_img_affiche[0].h=37;
minus.pos_img_ecran[0].x=1190;
minus.pos_img_ecran[0].y=435;
minus.pos_img_ecran[0].w=350;
minus.pos_img_ecran[0].h=53;

minus.pos_img_affiche[1].x=410;
minus.pos_img_affiche[1].y=1153;
minus.pos_img_affiche[1].w=120;
minus.pos_img_affiche[1].h=50;
minus.pos_img_ecran[1].x=1190;
minus.pos_img_ecran[1].y=435;
minus.pos_img_ecran[1].w=350;
minus.pos_img_ecran[1].h=53;

minus.pos_img_affiche[2].x=320;
minus.pos_img_affiche[2].y=1520;
minus.pos_img_affiche[2].w=450;
minus.pos_img_affiche[2].h=63;
minus.pos_img_ecran[2].x=1520;
minus.pos_img_ecran[2].y=435;
minus.pos_img_ecran[2].w=450;
minus.pos_img_ecran[2].h=63;
//***********************************
mute.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(mute.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
mute.pos_img_affiche[0].x=237;
mute.pos_img_affiche[0].y=916;
mute.pos_img_affiche[0].w=400;
mute.pos_img_affiche[0].h=45;
mute.pos_img_ecran[0].x=1260;
mute.pos_img_ecran[0].y=480;
mute.pos_img_ecran[0].w=350;
mute.pos_img_ecran[0].h=53;

mute.pos_img_affiche[1].x=212;
mute.pos_img_affiche[1].y=1200;
mute.pos_img_affiche[1].w=450;
mute.pos_img_affiche[1].h=50;
mute.pos_img_ecran[1].x=1260;
mute.pos_img_ecran[1].y=480;
mute.pos_img_ecran[1].w=350;
mute.pos_img_ecran[1].h=53;

mute.pos_img_affiche[2].x=226;
mute.pos_img_affiche[2].y=1523;
mute.pos_img_affiche[2].w=990;
mute.pos_img_affiche[2].h=80;
mute.pos_img_ecran[2].x=1260;
mute.pos_img_ecran[2].y=480;
mute.pos_img_ecran[2].w=990;
mute.pos_img_ecran[2].h=80;
//*********************************************************
fullscreen.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(fullscreen.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
fullscreen.pos_img_affiche[0].x=176;
fullscreen.pos_img_affiche[0].y=868;
fullscreen.pos_img_affiche[0].w=450;
fullscreen.pos_img_affiche[0].h=50;
fullscreen.pos_img_ecran[0].x=1160;
fullscreen.pos_img_ecran[0].y=535;
fullscreen.pos_img_ecran[0].w=350;
fullscreen.pos_img_ecran[0].h=53;

//**********************************************************************************
back.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(back.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
back.pos_img_affiche[0].x=290;
back.pos_img_affiche[0].y=960;
back.pos_img_affiche[0].w=450;
back.pos_img_affiche[0].h=66;
back.pos_img_ecran[0].x=1310;
back.pos_img_ecran[0].y=700;
back.pos_img_ecran[0].w=350;
back.pos_img_ecran[0].h=53;

back.pos_img_affiche[1].x=219;
back.pos_img_affiche[1].y=1350;
back.pos_img_affiche[1].w=450;
back.pos_img_affiche[1].h=68;
back.pos_img_ecran[1].x=1300;
back.pos_img_ecran[1].y=700;
back.pos_img_ecran[1].w=350;
back.pos_img_ecran[1].h=53;

back.pos_img_affiche[2].x=173;
back.pos_img_affiche[2].y=716;
back.pos_img_affiche[2].w=450;
back.pos_img_affiche[2].h=37;
back.pos_img_ecran[2].x=23+80;
back.pos_img_ecran[2].y=457;
back.pos_img_ecran[2].w=350;
back.pos_img_ecran[2].h=53;
//*****************************************************************************

/*keybinds.img=IMG_Load("/home/hazem/Desktop/Boutons Menuuu_.png") ;

if(keybinds.img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
keybinds.pos_img_affiche[0].x=171;
keybinds.pos_img_affiche[0].y=716;
keybinds.pos_img_affiche[0].w=450;
keybinds.pos_img_affiche[0].h=37;
keybinds.pos_img_ecran[0].x=23+80;
keybinds.pos_img_ecran[0].y=457;
keybinds.pos_img_ecran[0].w=350;
keybinds.pos_img_ecran[0].h=53;

keybinds.pos_img_affiche[1].x=173;
keybinds.pos_img_affiche[1].y=716;
keybinds.pos_img_affiche[1].w=450;
keybinds.pos_img_affiche[1].h=37;
keybinds.pos_img_ecran[1].x=23+80;
keybinds.pos_img_ecran[1].y=457;
keybinds.pos_img_ecran[1].w=350;
keybinds.pos_img_ecran[1].h=53;

keybinds.pos_img_affiche[2].x=173;
keybinds.pos_img_affiche[2].y=716;
keybinds.pos_img_affiche[2].w=450;
keybinds.pos_img_affiche[2].h=37;
keybinds.pos_img_ecran[2].x=23+80;
keybinds.pos_img_ecran[2].y=457;
keybinds.pos_img_ecran[2].w=350;
keybinds.pos_img_ecran[2].h=53;

*/




	texte txtt;
	int isSoundOn = 1;
	char volumeText[50] = "100";
	initialiser_texte(&txtt);
	txtt.pos_txt.x=1355;
	txtt.pos_txt.y=418;
	txtt.police=TTF_OpenFont("/home/hazem/Desktop/FortuneCoin.ttf",50);
	int leave=0;
	int position = 1;
	int isfullscreen=0,soundstate=1,lastvolume=100;
	volume.state=plus.state=minus.state=mute.state=fullscreen.state=back.state=keybinds.state=on.state=off.state=0;
while (!leave)
{		SDL_BlitSurface(background, NULL, screen, NULL);
		txtt.txt=TTF_RenderText_Blended(txtt.police,volumeText,txtt.color_txt);
		SDL_BlitSurface(txtt.txt, NULL, screen, &txtt.pos_txt);
		
		SDL_BlitSurface(volume.img, &volume.pos_img_affiche[volume.state], screen, &volume.pos_img_ecran[volume.state]);
		SDL_BlitSurface(on.img, &on.pos_img_affiche[on.state], screen, &on.pos_img_ecran[on.state]);
		SDL_BlitSurface(off.img, &off.pos_img_affiche[off.state], screen, &off.pos_img_ecran[off.state]);
		SDL_BlitSurface(plus.img, &plus.pos_img_affiche[plus.state], screen, &plus.pos_img_ecran[plus.state]);
		SDL_BlitSurface(minus.img, &minus.pos_img_affiche[minus.state], screen, &minus.pos_img_ecran[minus.state]);
		SDL_BlitSurface(mute.img, &mute.pos_img_affiche[mute.state], screen, &mute.pos_img_ecran[mute.state]);
		SDL_BlitSurface(fullscreen.img, &fullscreen.pos_img_affiche[fullscreen.state], screen, &fullscreen.pos_img_ecran[fullscreen.state]);
		SDL_BlitSurface(back.img, &back.pos_img_affiche[back.state], screen, &back.pos_img_ecran[back.state]);
		SDL_BlitSurface(keybinds.img, &keybinds.pos_img_affiche[keybinds.state], screen, &keybinds.pos_img_ecran[keybinds.state]);
		SDL_Flip(screen);
		int x, y;
		SDL_GetMouseState(&x, &y);
		volume.state=plus.state=minus.state=mute.state=fullscreen.state=back.state=keybinds.state=on.state=off.state=0;
 

		 if(y<=mute.pos_img_ecran[mute.state].y+50 && y>=mute.pos_img_ecran[mute.state].y+10 &&( x<=mute.pos_img_ecran[mute.state].x+300&& x>=mute.pos_img_ecran[mute.state].x)) 
			{
			mute.state=1;
			}
		else if(y<=on.pos_img_ecran[on.state].y+43 && y>=on.pos_img_ecran[on.state].y &&( x<=on.pos_img_ecran[on.state].x+90&& 	x>=on.pos_img_ecran[on.state].x)) 
		{
				on.state=1;
		}
		else if(y<=off.pos_img_ecran[off.state].y+43 && y>=off.pos_img_ecran[off.state].y &&( x<=off.pos_img_ecran[off.state].x+90&& 	x>=off.pos_img_ecran[off.state].x)) 
		{
				off.state=1;
		}
		else if(y<=plus.pos_img_ecran[plus.state].y+43 && y>=plus.pos_img_ecran[plus.state].y &&( x<=plus.pos_img_ecran[plus.state].x+90&& 	x>=plus.pos_img_ecran[plus.state].x)) 
		{
				plus.state=1;
		}
		
		else if(y<=minus.pos_img_ecran[minus.state].y+36 && y>=minus.pos_img_ecran[minus.state].y &&( x<=minus.pos_img_ecran[minus.state].x+104&& x>=minus.pos_img_ecran[minus.state].x)) 
		{
		minus.state=1;
		}

		else if(y<=back.pos_img_ecran[back.state].y+64 && y>=back.pos_img_ecran[back.state].y &&( x<=back.pos_img_ecran[back.state].x+220&& x>=back.pos_img_ecran[back.state].x)) 
		{
		back.state=1;
		}
//for keybinds
		/*else if(y<=back.pos_img_ecran[back.state].y && y>=back.pos_img_ecran[back.state].y &&( x<=back.pos_img_ecran[back.state].x&& x>=back.pos_img_ecran[back.state].x)) 
		{
		back.state=1;
		}*/
		
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
		case SDL_QUIT:
			leave=1;
			break;
		case SDL_KEYDOWN:
		
			if (event.key.keysym.sym == SDLK_b)
			{
				leave=1;
				
			}
//*************************************************FULLSCREEN****************************************************************
			else if ((event.key.keysym.sym == SDLK_f)&&(isfullscreen==0))
			{
                           	 	screen = SDL_SetVideoMode(1550, 872, 32, SDL_SWSURFACE | SDL_FULLSCREEN|SDL_DOUBLEBUF|SDL_RESIZABLE);
					isfullscreen=1;
             
			}
			else if ((event.key.keysym.sym == SDLK_g)&&(isfullscreen==1))
			{
				screen = SDL_SetVideoMode(1550, 872, 32, SDL_SWSURFACE |SDL_DOUBLEBUF);
					isfullscreen=0;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=on.pos_img_ecran[on.state].y+43 && event.button.y>=on.pos_img_ecran[on.state].y &&( event.button.x<=on.pos_img_ecran[on.state].x+230&& event.button.x>=on.pos_img_ecran[on.state].x))&& isfullscreen==0)
			{
				
                        		screen = SDL_SetVideoMode(1550, 872, 32, SDL_SWSURFACE | SDL_FULLSCREEN|SDL_DOUBLEBUF|SDL_RESIZABLE);
					isfullscreen=1;
					on.state=2;
                       	}	
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=off.pos_img_ecran[off.state].y+43 && event.button.y>=off.pos_img_ecran[off.state].y &&( event.button.x<=off.pos_img_ecran[off.state].x+230&& event.button.x>=off.pos_img_ecran[off.state].x))&& isfullscreen==1)
				
			{
                           		 screen = SDL_SetVideoMode(1550, 872, 32, SDL_SWSURFACE |SDL_DOUBLEBUF);
					isfullscreen=0;
					off.state=2;
                        }


//*************************************************SOUND****************************************************************
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=minus.pos_img_ecran[minus.state].y+36 && event.button.y>=minus.pos_img_ecran[minus.state].y &&( event.button.x<=minus.pos_img_ecran[minus.state].x+104&& event.button.x>=minus.pos_img_ecran[minus.state].x)))
			{
				minus.state=2;
				lastvolume=lastvolume-10;
				if(lastvolume<0)
					lastvolume=0;
				Mix_VolumeMusic(lastvolume);
				sprintf(volumeText,"%d",lastvolume*1);
			}
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=plus.pos_img_ecran[plus.state].y+36 && event.button.y>=plus.pos_img_ecran[plus.state].y &&( event.button.x<=plus.pos_img_ecran[plus.state].x+104 && event.button.x>=plus.pos_img_ecran[plus.state].x)))
			{
				plus.state=2;
				lastvolume=lastvolume+10;
				if(lastvolume>100)
					lastvolume=100;
				Mix_VolumeMusic(lastvolume);
				sprintf(volumeText,"%d",lastvolume*1);
			}
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=mute.pos_img_ecran[mute.state].y+36 && event.button.y>=mute.pos_img_ecran[mute.state].y &&( event.button.x<=mute.pos_img_ecran[mute.state].x+270&& event.button.x>=mute.pos_img_ecran[mute.state].x)))
			{
				if (soundstate==1)
					{
					Mix_VolumeMusic(0);
					soundstate=0;
					sprintf(volumeText,"%d",0);		
					}
				else
					{Mix_VolumeMusic(lastvolume);
					soundstate=1;
					sprintf(volumeText,"%d",lastvolume);
					}
			
			}
			if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.y<=back.pos_img_ecran[back.state].y+64 && event.button.y>=back.pos_img_ecran[back.state].y &&( event.button.x<=back.pos_img_ecran[back.state].x+220&& event.button.x>=back.pos_img_ecran[back.state].x)))
			{
				leave=1;
			}
			break;

		}
		}	
    }
} 

void initialiser_imageBACK(image *imge,char* url) 
{	imge->img=IMG_Load(url);

if (imge->img == NULL) 
{
printf ("unable to load background image %s \n",SDL_GetError());
return ;
}
imge->pos_img_ecran[0].x=0;
imge->pos_img_ecran[0].y=0;
imge->pos_img_affiche[0].x=0;
imge->pos_img_affiche[0].y=0;
imge->pos_img_affiche[0].h=1080;
imge->pos_img_affiche[0].w=1920;
}


/*void initialiser_imageBOUTON1 (image *imgbtn)
{

imgbtn->url="/home/hazem/Desktop/menu/resources/menu_buttons_sprite.png";


imgbtn->img=IMG_Load(imgbtn->url);
	if(imgbtn->img == NULL) {
		printf ("unable to load background image %s \n",SDL_GetError());
	return ;}


imgbtn->pos_img_affiche[0].x=27;
imgbtn->pos_img_affiche[0].y=55;
//pos image%background
imgbtn->pos_img_affiche[0].w=320;
imgbtn->pos_img_affiche[0].h=200;

imgbtn->pos_img_ecran[0].x=400;
imgbtn->pos_img_ecran[0].y=200;
imgbtn->pos_img_ecran[0].x=100;
imgbtn->pos_img_ecran[0].y=100;



}
 */
void initialiser_imageBOUTON1(image *imgbtn)
{
imgbtn->url="/home/hazem/Desktop/Boutons Menuuu_.png";
imgbtn->img=IMG_Load(imgbtn->url) ;
if(imgbtn->img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
//etat initial
imgbtn->pos_img_affiche[0].x=32;
imgbtn->pos_img_affiche[0].y=40;
	//pos image%background
imgbtn->pos_img_affiche[0].w=450;
imgbtn->pos_img_affiche[0].h=37;

imgbtn->pos_img_ecran[0].x=23+80;
imgbtn->pos_img_ecran[0].y=457;
imgbtn->pos_img_ecran[0].w=350;
imgbtn->pos_img_ecran[0].h=53;

//hover state
imgbtn->pos_img_affiche[1].x=32;
imgbtn->pos_img_affiche[1].y=210;
//pos image%background
imgbtn->pos_img_affiche[1].w=450;
imgbtn->pos_img_affiche[1].h=37;

imgbtn->pos_img_ecran[1].x=23+80;
imgbtn->pos_img_ecran[1].y=457;
imgbtn->pos_img_ecran[1].w=350;
imgbtn->pos_img_ecran[1].h=53;


//click animation
imgbtn->pos_img_affiche[2].x=22;
imgbtn->pos_img_affiche[2].y=368;
//pos image%background
imgbtn->pos_img_affiche[2].w=450;
imgbtn->pos_img_affiche[2].h=48;
imgbtn->pos_img_ecran[2].x=14+80;
imgbtn->pos_img_ecran[2].y=448;
imgbtn->pos_img_ecran[2].w=350;
imgbtn->pos_img_ecran[2].h=53;
}

 

void initialiser_imageBOUTON2(image *imgbtn)
{
imgbtn->url="/home/hazem/Desktop/Boutons Menuuu_.png";
imgbtn->img=IMG_Load(imgbtn->url) ;
if(imgbtn->img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}

imgbtn->pos_img_affiche[0].x=25;
imgbtn->pos_img_affiche[0].y=84;
//pos image%background
imgbtn->pos_img_affiche[0].w=450;
imgbtn->pos_img_affiche[0].h=49;

imgbtn->pos_img_ecran[0].x=18+80;
imgbtn->pos_img_ecran[0].y=505;
imgbtn->pos_img_ecran[0].w=100;
imgbtn->pos_img_ecran[0].h=100;

//hover state
imgbtn->pos_img_affiche[1].x=32;
imgbtn->pos_img_affiche[1].y=253;
//pos image%background
imgbtn->pos_img_affiche[1].w=450;
imgbtn->pos_img_affiche[1].h=49;

imgbtn->pos_img_ecran[1].x=18+80;
imgbtn->pos_img_ecran[1].y=505;
imgbtn->pos_img_ecran[1].w=100;
imgbtn->pos_img_ecran[1].h=100;


//click animation
imgbtn->pos_img_affiche[2].x=25;
imgbtn->pos_img_affiche[2].y=420;
//pos image%background
imgbtn->pos_img_affiche[2].w=450;
imgbtn->pos_img_affiche[2].h=58;
imgbtn->pos_img_ecran[2].x=14+80;
imgbtn->pos_img_ecran[2].y=498;
imgbtn->pos_img_ecran[2].w=100;
imgbtn->pos_img_ecran[2].h=100;
}
void initialiser_imageBOUTON3(image *imgbtn)
{
imgbtn->url="/home/hazem/Desktop/Boutons Menuuu_.png";
imgbtn->img=IMG_Load(imgbtn->url) ;
if(imgbtn->img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
imgbtn->pos_img_affiche[0].x=38;
imgbtn->pos_img_affiche[0].y=561;
//pos image%background
imgbtn->pos_img_affiche[0].w=450;
imgbtn->pos_img_affiche[0].h=40;

imgbtn->pos_img_ecran[0].x=30+80;
imgbtn->pos_img_ecran[0].y=568;
imgbtn->pos_img_ecran[0].w=100;
imgbtn->pos_img_ecran[0].h=100;

//hover state
imgbtn->pos_img_affiche[1].x=38;
imgbtn->pos_img_affiche[1].y=614;
//pos image%background
imgbtn->pos_img_affiche[1].w=450;
imgbtn->pos_img_affiche[1].h=40;


imgbtn->pos_img_ecran[1].x=28+80;
imgbtn->pos_img_ecran[1].y=566;
imgbtn->pos_img_ecran[1].w=100;
imgbtn->pos_img_ecran[1].h=100;


//click animation
imgbtn->pos_img_affiche[2].x=31;
imgbtn->pos_img_affiche[2].y=655;
//pos image%background
imgbtn->pos_img_affiche[2].w=450;
imgbtn->pos_img_affiche[2].h=45;

imgbtn->pos_img_ecran[2].x=23+80;
imgbtn->pos_img_ecran[2].y=555;
imgbtn->pos_img_ecran[2].w=100;
imgbtn->pos_img_ecran[2].h=100;

}
void initialiser_imageBOUTON4(image *imgbtn)
{
imgbtn->url="/home/hazem/Desktop/Boutons Menuuu_.png";
imgbtn->img=IMG_Load(imgbtn->url) ;
if(imgbtn->img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
imgbtn->pos_img_affiche[0].x=27;
imgbtn->pos_img_affiche[0].y=142;
//pos image%background
imgbtn->pos_img_affiche[0].w=450;
imgbtn->pos_img_affiche[0].h=47;




imgbtn->pos_img_ecran[0].x=18+80;
imgbtn->pos_img_ecran[0].y=630;
imgbtn->pos_img_ecran[0].w=100;
imgbtn->pos_img_ecran[0].h=100;


imgbtn->pos_img_affiche[1].x=27;
imgbtn->pos_img_affiche[1].y=310;
//pos image%background
imgbtn->pos_img_affiche[1].w=450;
imgbtn->pos_img_affiche[1].h=47;



imgbtn->pos_img_ecran[1].x=18+80;
imgbtn->pos_img_ecran[1].y=630;
imgbtn->pos_img_ecran[1].w=100;
imgbtn->pos_img_ecran[1].h=100;

//click animation
imgbtn->pos_img_affiche[2].x=23;
imgbtn->pos_img_affiche[2].y=478;
//pos image%background
imgbtn->pos_img_affiche[2].w=450;
imgbtn->pos_img_affiche[2].h=57;

imgbtn->pos_img_ecran[2].x=14+80;
imgbtn->pos_img_ecran[2].y=625;
imgbtn->pos_img_ecran[2].w=100;
imgbtn->pos_img_ecran[2].h=100;
}

void afficher_imageBMP(SDL_Surface *screen,image imge)
{
imge.state=0;
SDL_BlitSurface(imge.img, &(imge.pos_img_affiche[0]), screen, &(imge.pos_img_ecran[0])) ;
}







void afficher_imageBTN1(SDL_Surface *screen, image imge)
{

SDL_BlitSurface(imge.img,&imge.pos_img_affiche[imge.state], screen,&imge.pos_img_ecran[imge.state] ) ;
}


void afficher_imageBTN2(SDL_Surface *screen, image imge)
{

SDL_BlitSurface(imge.img,&imge.pos_img_affiche[imge.state], screen,&imge.pos_img_ecran[imge.state]) ;
}

void afficher_imageBTN3(SDL_Surface *screen, image imge)
{

SDL_BlitSurface(imge.img,&imge.pos_img_affiche[imge.state], screen,&imge.pos_img_ecran[imge.state]) ;
}

void afficher_imageBTN4(SDL_Surface *screen, image imge)
{

SDL_BlitSurface(imge.img,&imge.pos_img_affiche[imge.state], screen,&imge.pos_img_ecran[imge.state]) ;
}








void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}


void initialiser_audio(Mix_Music *music)
{
if(Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1){
printf("%s",SDL_GetError());
}   

music=Mix_LoadMUS("/home/hazem/Desktop/04 - saga.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(100);
}

void liberer_musique(Mix_Music *music)
{
Mix_FreeMusic(music);
}


void initialiser_audiobref(Mix_Chunk *mus)
{
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, 2, 2048);
	mus=Mix_LoadWAV("/home/hazem/Desktop/punch-boxing-02wav-14897.mp3");
	Mix_PlayChannel (-1,mus,0);
	if (mus == NULL) printf("%s", SDL_GetError());
}
void liberer_audiobref(Mix_Chunk *mus)
{
	Mix_FreeChunk(mus);
}
void initialiser_texte(texte *txte)
{
TTF_Init();
txte->police=TTF_OpenFont("/home/hazem/Desktop/FortuneCoin.ttf",25);
txte->color_txt.r=0;
txte->color_txt.g=0;
txte->color_txt.b=0;
txte->pos_txt.x=125;
txte->pos_txt.y=727;
}



void afficher_texte(SDL_Surface *screen, texte txte)
{
txte.txt=TTF_RenderText_Blended(txte.police,"PIXELIZED",txte.color_txt);
SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
  
}
   

void Liberer_texte (texte txte)
{
TTF_CloseFont(txte.police);
 
}


/*void refresh()
{afficher_imageBMP(screen,IMAGE);}*/
