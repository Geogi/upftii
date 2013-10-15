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

#include "game.hh"
#include "fight.hh"

void upftii_Game::init() {
  this->status = 0;

  SDL_Init(SDL_INIT_EVERYTHING);
  MagickWandGenesis();
  this->win = SDL_CreateWindow(this->name, 100, 100, this->WWIDTH, this->WHEIGHT, SDL_WINDOW_SHOWN);
  this->ren = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED);
  
  this->fight.init(this);
}

void upftii_Game::finalize() {
  free(this->lastev);
  SDL_Quit();
  MagickWandTerminus();
}

int upftii_Game::quit() {
  return this->status;
}

void upftii_Game::update() {
  while (SDL_PollEvent(this->lastev)) {
    switch (this->lastev->type) {
    case SDL_QUIT: this->status = 1; break;
    case SDL_KEYDOWN:
      switch(this->lastev->key.keysym.sym) {
      case SDLK_ESCAPE: this->status = 1; break;
      case SDLK_RIGHT: this->fight.startright(); break;
      case SDLK_LEFT: this->fight.startleft(); break;
      }
      break;
    case SDL_KEYUP:
      switch(this->lastev->key.keysym.sym) {
      case SDLK_RIGHT:
      case SDLK_LEFT: this->fight.stopmove(); break;
      }
    }
  }
  SDL_RenderClear(this->ren);
  fight.update(this);
  SDL_RenderPresent(this->ren);
  SDL_Delay(1);
}
