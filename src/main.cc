#include <iostream>
#include <SDL2/SDL.h>
#include <png.h>

/* This program is currently a test, largely helped by twinklebear.github.io's excellent tutorial
 * so thanks to him/her */
int main(int argc, char **argv){
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 1280, 768, SDL_WINDOW_SHOWN);
  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 
					 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  //try to read from pngs
  png_image *img = (png_image*) malloc(sizeof(png_image));
  memset(img, 0, sizeof(png_image));
  png_image_begin_read_from_file(img, "res/left.png");
  img->format = PNG_FORMAT_RGB;
  void *buffer = malloc(300000);
  png_image_finish_read(img, NULL, buffer, 1, NULL);
  free(img);
  //end

  SDL_RWops *stream = SDL_RWFromMem(buffer, 300000);
  SDL_Surface *sur = SDL_LoadBMP_RW(stream, 1);
  if(sur == nullptr) {
    std::cout << SDL_GetError() << std::endl;
    return 1;
  }
  free(buffer);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, sur);
  SDL_FreeSurface(sur);

  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, tex, NULL, NULL);
  SDL_RenderPresent(ren);

  SDL_Delay(2000);

  SDL_Quit();
  return 0;
}
