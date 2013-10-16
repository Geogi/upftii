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
class upftii_Fighter;

class upftii_Fight {
  // temporary
  const char *leftdir = DATA_PATH "/left/all.png";
  const char *rightdir = DATA_PATH "/right/all.png";
  const char *bgfile = DATA_PATH "/bg.png";

  SDL_Texture *bg;
public:
  upftii_Fight(upftii_Game *game);

  upftii_Game *game;
  upftii_Fighter *left, *right;

  void update();
  void updateFacing();
};

#endif
