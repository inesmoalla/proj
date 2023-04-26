#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "game.h"
void intit_Loadingscreen(background *b,int loading)
{
b->camera_pos.x=0;
b->camera_pos.y=0;
char filename[65];
sprintf(filename,"/home/ines/background/LOADINGanim/%d.jpg",loading);        
b->loading=IMG_Load(filename); 
b->op_loading=SDL_DisplayFormat(b->loading);
SDL_FreeSurface(b->loading);
}
void afficher_LoadingScreen(background b,SDL_Surface *screen)
{
    SDL_BlitSurface(b.op_loading,NULL,screen,NULL); 
    SDL_FreeSurface(b.op_loading);
}
void intit_heart(background *b)
{
b->pos_heart.x=0;
b->pos_heart.y=0;
char filename[65];
        
b->vie=IMG_Load("heart.png"); 
b->op_vie=SDL_DisplayFormatAlpha(b->vie);
SDL_FreeSurface(b->vie);
}
void afficher_heart(background b,SDL_Surface *screen)
{
    SDL_BlitSurface(b.op_vie,NULL,screen,NULL); 
    SDL_FreeSurface(b.op_vie);
}
void initBack(background *b)
{
b->camera_pos.x=0;
b->camera_pos.y=0;
b->camera_pos.w=1920;
b->camera_pos.h=1080;
b->pos_img.x=0;
b->pos_img.y=0;
b->pos_img.x=0;
b->pos_img.y=0;
b->pos_img.w=1920;
b->pos_img.h=1080;
}
void init_bgimage(background *b)
{
b->bg=IMG_Load("bgg.jpg");
b->op_bg=SDL_DisplayFormat(b->bg);
SDL_FreeSurface(b->bg);
}
void aficherBack(background b,SDL_Surface *screen)
{
SDL_BlitSurface(b.op_bg,&b.pos_img,screen,&b.camera_pos);
SDL_FreeSurface(b.op_bg);
}
void initialiser_audio(Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
printf("%s",SDL_GetError());
}
music=Mix_LoadMUS("lol.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME);
}

void scrolling(background *b,SDL_Event event)
{
    uint8_t* keystate=SDL_GetKeyState(NULL);
    switch(event.type)
{
case SDL_KEYDOWN:
if(keystate[SDLK_RIGHT])
{
b->camera_pos.x-=5;}
if(keystate[SDLK_LEFT])
{
b->camera_pos.x+=5;}
}
/////////////:acceleration
if(keystate[SDLK_RIGHT]&&keystate[SDLK_LSHIFT])
{
b->camera_pos.x-=10;}
if(keystate[SDLK_LEFT]&&keystate[SDLK_LSHIFT])
{
b->camera_pos.x+=10;}
}
void libererbg(background b)
{
  SDL_FreeSurface(b.paysage);
}
void libererloading(background b)
{
  SDL_FreeSurface(b.loading);
}
void save_score(background b,char filename[])
{
FILE* f=NULL;
f=fopen(filename,"w");
if(f==NULL)
printf("erreur");
else
{fprintf(f,"%s  %f \n",b.scorename,b.score_player);
}fclose(f);
}

void meilleur (char filename[],background *b)
{
TTF_Init();
int i=0;
FILE *f;
char text1[30];
char text2[30];
char text3[30];
      int tmp;
    int tab[50];//tab score
    f = fopen(filename, "r");

 if(f==NULL)
	{
        printf("Erreur lors de l'ouverture d'un fichier");
        }
else
{
while(fscanf(f,"%d\n",&tab[i])==1)
{
	i++;
}}

    	


 for (int k=0 ; k < i-1; k++)
  {
    for (int j=0 ; j < i-k-1; j++)
    {
      /* Pour un ordre décroissant utiliser < */
      if (tab[j] > tab[j+1]) 
      {
        tmp = tab[j];
        tab[j] = tab[j+1];
        tab[j+1] = tmp;
      }
    }
  }

for(int j=0;j<i;j++) //testt
 	{printf(" tri score : %d\n", tab[j]);
}
printf("i est  %d\n",i);
sprintf(text1, "%d",tab[i-1]);
sprintf(text2, "%d",tab[i-2]);
sprintf(text3, "%d",tab[i-3]);

printf("text1 est  %s\n",text1);
printf("text2 est  %s\n",text2);
printf("text3 est  %s\n",text3);



	SDL_Color couleur = {0,0,0}; 
	SDL_Color couleur1 = {255,0,0}; 

	(*b).police = TTF_OpenFont("temp.ttf", 30);
 	b->reponses[0]=TTF_RenderText_Blended(b->police,text1, couleur); 
 	b->reponses[1]=TTF_RenderText_Blended(b->police,text2, couleur); 
 	b->reponses[2]=TTF_RenderText_Blended(b->police,text3, couleur); 
        b->reponses[3]=TTF_RenderText_Blended(b->police,"les 3 meilleurs scores:", couleur1); 
        b->pos_reponse1txt.x=50;//position el texte fil bouton bich ijini fil bouton bidhbt 
	b->pos_reponse1txt.y=300;
	b->pos_reponse2txt.x=50;
	b->pos_reponse2txt.y=400;
	b->pos_reponse3txt.x=50;
	b->pos_reponse3txt.y=500;
        b->pos_meilleurtxt.x=50;
        b->pos_meilleurtxt.y=200;
}

   
void init_boutton(background *b)
{b->boutton=IMG_Load("boutton.png");
b->positionbotton.x=0;
b->positionbotton.x=-100;
}
void afficher_boutton(background b,SDL_Surface *screen)
{SDL_BlitSurface(b.boutton,NULL,screen,&b.positionbotton);
}

void afficher(background b,SDL_Surface *screen)
{

 SDL_BlitSurface(b.reponses[0], NULL, screen, &b.pos_reponse1txt);
 SDL_BlitSurface(b.reponses[1], NULL, screen, &b.pos_reponse2txt);
 SDL_BlitSurface(b.reponses[2], NULL, screen, &b.pos_reponse3txt);
 SDL_BlitSurface(b.reponses[3], NULL, screen, &b.pos_meilleurtxt);
   SDL_Flip(screen);
}
void affichageMeilleur(SDL_Surface *screen,background b)
{
       afficher(b,screen);
}

