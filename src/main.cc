/* Copyright (C) 2013 Paul Blouët
   
   This file is part of UPFTII.

   UPFTII is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   UPFTII is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with UPFTII.  If not, see <http://www.gnu.org/licenses/>. */

#include <iostream>
#include <SDL2/SDL.h>
#include <wand/MagickWand.h>

void init();
void finalize();
SDL_Texture *png2tex(const char *filename, SDL_Renderer *ren);

int main(int argc, char **argv){
  const int WHEIGHT = 768, WWIDTH = 1280;

  init();
  SDL_Window *win = SDL_CreateWindow("ULTIMATE PRO FIGHTER TURBO II", 100, 100, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

  SDL_Texture *left = png2tex("res/left.png", ren);
  SDL_Texture *right = png2tex("res/right.png", ren);
  SDL_Texture *bg = png2tex("res/bg.png", ren);
  int lh, lw, rh, rw;
  SDL_QueryTexture(left, NULL, NULL, &lw, &lh);
  SDL_QueryTexture(right, NULL, NULL, &rw, &rh);
  
  SDL_Rect lr, rr;
  lr.x = 50;
  lr.y = WHEIGHT - lh - 100;
  lr.w = lw;
  lr.h = lh;
  rr.x = WWIDTH - rw - 50;
  rr.y = WHEIGHT - rh - 100;
  rr.w = rw;
  rr.h = rh;
  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, bg, NULL, NULL);
  SDL_RenderCopy(ren, left, NULL, &lr);
  SDL_RenderCopy(ren, right, NULL, &rr);
  SDL_RenderPresent(ren);

  SDL_Delay(2000);

  finalize();
  return 0;
}

SDL_Texture *png2tex(const char *filename, SDL_Renderer *ren) {
  // convert filename to BMP in-memory
  MagickWand *wand = NewMagickWand();
  MagickReadImage(wand, filename);
  MagickSetImageFormat(wand, "BMP");
  size_t buffer_size;
  unsigned char *buffer = MagickGetImageBlob(wand, &buffer_size);

  // create SDL texture from BMP and return it
  SDL_RWops *stream = SDL_RWFromMem(buffer, buffer_size);
  SDL_Surface *sur = SDL_LoadBMP_RW(stream, 1);
  MagickRelinquishMemory(buffer);
  DestroyMagickWand(wand);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, sur);
  SDL_FreeSurface(sur);
  
  return tex;
}

void init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  MagickWandGenesis();
}
void finalize() {
  SDL_Quit();
  MagickWandTerminus();
}
