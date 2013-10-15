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

#include "game.h"

void upftii_Game::init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  MagickWandGenesis();
  this->win = SDL_CreateWindow(this->name, 100, 100, this->WWIDTH, this->WHEIGHT, SDL_WINDOW_SHOWN);
  this->ren = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED);
}

void upftii_Game::finalize() {
  SDL_Quit();
  MagickWandTerminus();
}
