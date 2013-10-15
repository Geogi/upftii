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

#ifndef UPFTII_GAME_H
#define UPFTII_GAME_H

#include <SDL2/SDL.h>

#include "fight.hh"

class upftii_Game {
  const char *name = "ULTIMATE PRO FIGHTER TURBO II";

  SDL_Window *win;
  SDL_Event *lastev;
  bool playing;
public:
  const int WWIDTH = 1280, WHEIGHT = 768;

  upftii_Fight *fight;
  SDL_Renderer *ren;

  void init();
  void finalize();
  void update();
  bool isPlaying();
};

#endif

