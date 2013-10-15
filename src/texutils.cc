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

#include <SDL2/SDL.h>
#include <wand/MagickWand.h>

#include "texutils.h"

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
