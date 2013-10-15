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

#ifndef UPFTII_FIGHT_H
#define UPFTII_FIGHT_H

#include <SDL2/SDL.h>

class upftii_Game;

class upftii_Fight {
  const char *leftfile = "res/left.png";
  const char *rightfile = "res/right.png";
  const char *bgfile = "res/bg.png";
  SDL_Rect lr, rr;
  SDL_Texture *left, *right, *bg;
public:
  void init(upftii_Game *game);
  void update(upftii_Game *game);
};

#endif
