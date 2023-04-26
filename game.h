#ifndef game_H_INCLUDED
#define game_W_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{ SDL_Surface *paysage,*loading,*op_loading,*bg,*op_bg,*vie,*op_vie;
  SDL_Rect pos_img,pos_heart;
  SDL_Rect camera_pos;
  int level;
  char scorename[20];
  float score_player;
SDL_Surface *boutton;
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Rect pos3;
SDL_Rect pos_reponse1txt;
SDL_Rect pos_reponse2txt;
SDL_Rect pos_reponse3txt;
SDL_Rect pos_meilleurtxt;
TTF_Font *police;
SDL_Surface *reponses[4];
SDL_Rect positionbotton;


}background;


void intit_Loadingscreen(background *b,int loading);
void afficher_LoadingScreen(background b,SDL_Surface *screen);
void initBack(background *b);
void init_bgimage(background *b);
void aficherBack(background b,SDL_Surface *screen);
void initialiser_audio(Mix_Music *music);
void scrolling(background *b,SDL_Event event);
void animerBack(background *b);
void initimage(background *b);
void aficherimage(background b,SDL_Surface *screen);
void libererbg(background b);
void libererloading(background b);
void afficher_heart(background b,SDL_Surface *screen);
void intit_heart(background *b);
void save_score(background b,char filename[]);
void meilleur (char filename[],background *b);
void init_boutton(background *b);
void afficher_boutton(background b,SDL_Surface *screen);
void afficher(background b,SDL_Surface *screen);
void affichageMeilleur(SDL_Surface *screen,background b);
#endif
