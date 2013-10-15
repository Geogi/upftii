#include <iostream>
#include <SDL2/SDL.h>

/* This program is currently a test, largely helped by twinklebear.github.io's excellent tutorial
 * so thanks to him/her */
int main(int argc, char **argv){
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 1280, 768, SDL_WINDOW_SHOWN);
  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 
					 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  SDL_Surface *sur = SDL_CreateRGBSurface(0, 200, 500, 32, 0, 0, 0, 0);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, sur);
  SDL_FreeSurface(sur);

  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, tex, NULL, NULL);
  SDL_RenderPresent(ren);

  SDL_Delay(2000);

  SDL_Quit();
  return 0;
}
