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
#include "fighter.hh"

void upftii_Game::init() {
  playing = true;

  SDL_Init(SDL_INIT_EVERYTHING);
  MagickWandGenesis();
  win = SDL_CreateWindow(name, 100, 100, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN);
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  
  fight = new upftii_Fight(this);
}

void upftii_Game::finalize() {
  SDL_Quit();
  MagickWandTerminus();
}

bool upftii_Game::isPlaying() {
  return playing;
}

void upftii_Game::update() {
  // Events
  while (SDL_PollEvent(lastev)) {
    switch (lastev->type) {
    case SDL_QUIT: playing = false; break;
    case SDL_KEYDOWN:
      switch(lastev->key.keysym.sym) {
      case SDLK_ESCAPE: playing = false; break;
      case SDLK_RIGHT: fight->left->move(true); break;
      case SDLK_LEFT: fight->left->move(false); break;
      }
      break;
    case SDL_KEYUP:
      switch(lastev->key.keysym.sym) {
      case SDLK_RIGHT:
      case SDLK_LEFT: fight->left->stop(); break;
      }
    }
  }

  // Render
  SDL_RenderClear(ren);
  fight->update();
  SDL_RenderPresent(ren);

  // Sleep
  SDL_Delay(1);
}
