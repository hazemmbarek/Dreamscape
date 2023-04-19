#include "Enigme.h"


void AfficherEnigme(enigme * e,SDL_Surface * screen)
{   
SDL_BlitSurface(e->images[e->current_frame],NULL,screen,NULL);
SDL_BlitSurface(e->text_e,NULL,screen,&e->postext_e);
SDL_BlitSurface(e->text_question,NULL,screen,&e->postext_question);
SDL_BlitSurface(e->text_r1,NULL,screen,&e->postext_r1);
SDL_BlitSurface(e->text_r2,NULL,screen,&e->postext_r2);
SDL_BlitSurface(e->text_r3,NULL,screen,&e->postext_r3);
}


void animerEnigme(enigme * e) 
{
    int delay_frames = 20;

    e->frame_counter++;

    if (e->frame_counter == delay_frames)
    {
        e->current_frame++;
        e->frame_counter = 0;
    }

    if (e->current_frame >= 37)
    {
        e->current_frame = 0;
    }
}



void initialiser_enigme(enigme *e)
{
    SDL_Color couleurBlanche = {255, 255, 255};

    e->background = IMG_Load("background.jpg");
    e->posbackground.x = 0;
    e->posbackground.y = 0;
    e->posbackground.w = 1024;
    e->posbackground.h = 1024;

int i;
e->current_frame=0;
char nom_frame[40];
	for (i = 0; i<37 ; i++)
		{
		sprintf(nom_frame,"background%d.jpg",i);
		e->images[i] = IMG_Load(nom_frame);
		printf("%s\n",nom_frame);
		}

    if (e->background == NULL) 
	{
        printf("Unable to set enigme background: %s\n", SDL_GetError());
	}


	e->police_e = TTF_OpenFont("roboto", 40);
    if (e->police_e == NULL) 
	{
        printf("Unable to load font: %s\n", TTF_GetError());
	}

    e->text_e = TTF_RenderText_Blended(e->police_e, "You must release yourself !", couleurBlanche);
    if (e->text_e == NULL) {
        printf("Unable to render text: %s\n", TTF_GetError());
	}

    e->postext_e.x = 250;
    e->postext_e.y = 50;

    e->postext_question.x = 125;
    e->postext_question.y = 200;

    e->postext_r1.x = 100;
    e->postext_r1.y = 400;

    e->postext_r2.x = 350;
    e->postext_r2.y = 400;

    e->postext_r3.x = 600;
    e->postext_r3.y = 400;


    e->text_question = TTF_RenderText_Blended(e->police_e, e->question, couleurBlanche);
    if (e->text_question == NULL) {
        printf("Unable to render text: %s\n", TTF_GetError());
    }

    e->text_r1 = TTF_RenderText_Blended(e->police_e, e->answer1, couleurBlanche);
    if (e->text_r1 == NULL) {
        printf("Unable to render text: %s\n", TTF_GetError());
    }

    e->text_r2 = TTF_RenderText_Blended(e->police_e, e->answer2, couleurBlanche);
    if (e->text_r2 == NULL) {
        printf("Unable to render text: %s\n", TTF_GetError());
    }

    e->text_r3 = TTF_RenderText_Blended(e->police_e, e->answer3, couleurBlanche);
    if (e->text_r3 == NULL) {
        printf("Unable to render text: %s\n", TTF_GetError());
    }
}


void GenererEnigme(enigme * e)
{
char nomfichier[10];
FILE *f;
int j;
srand(time(NULL));

j= rand() % 6;
sprintf(nomfichier,"%d.txt",j);
f=fopen(nomfichier,"r");
fscanf(f,"%s %s %s %s %d",e->question,e->answer1,e->answer2,e->answer3,&e->right_answer);

fclose(f);
}
