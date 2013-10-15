#include <iostream>
#include <SDL2/SDL.h>
#include <wand/MagickWand.h>

/* This program is currently a test, largely helped by twinklebear.github.io's excellent tutorial
 * so thanks to him/her */
int main(int argc, char **argv){
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 1280, 768, SDL_WINDOW_SHOWN);
  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 
					 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  MagickWandGenesis();
  MagickWand *wand = NewMagickWand();
  MagickReadImage(wand, "res/left.png");
  MagickSetImageFormat(wand, "BMP");
  size_t buffer_size;
  unsigned char *buffer = MagickGetImageBlob(wand, &buffer_size);

  SDL_RWops *stream = SDL_RWFromMem(buffer, buffer_size);
  SDL_Surface *sur = SDL_LoadBMP_RW(stream, 1);
  if(sur == nullptr) {
    std::cout << SDL_GetError() << std::endl;
    return 1;
  }
  MagickRelinquishMemory(buffer);
  DestroyMagickWand(wand);
  MagickWandTerminus();

  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, sur);
  SDL_FreeSurface(sur);

  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, tex, NULL, NULL);
  SDL_RenderPresent(ren);

  SDL_Delay(2000);

  SDL_Quit();
  return 0;
}
