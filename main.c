
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "game.h"
int main(){
int boucle=1,loading_counter=1;
background b,*bg,loading,vie;
SDL_Surface *screen;
Uint32 black;
Mix_Music *music;
SDL_Event event;

screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
initBack(&b);
initialiser_audio(music);

black=SDL_MapRGB(screen->format,0,188,0);
meilleur ("score.txt",&b);

while(boucle){
    if(loading_counter<=230){
    intit_Loadingscreen(&loading,loading_counter);
    afficher_LoadingScreen(loading,screen);
    loading_counter++;}
    if(loading_counter==231)
    {
    SDL_FillRect(screen,NULL,black);
    init_bgimage(&b);
    scrolling(&b,event);
    aficherBack(b,screen);
    intit_heart(&vie);
     afficher_heart(vie,screen);
init_boutton(&b);
 afficher_boutton(b,screen);
       }
while(SDL_PollEvent(&event))
{       
switch(event.type)
{
case SDL_QUIT:
boucle=0;
break;

case SDLK_b:
affichageMeilleur(screen,b);
SDL_Flip(screen);
break;
}
}
SDL_Flip(screen);
}
save_score(b,"score.txt");
libererbg(b);
libererbg(loading);
SDL_Quit();
return 0;}
