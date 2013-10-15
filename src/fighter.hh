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

#ifndef UPFTII_FIGHTER_H
#define UPFTII_FIGHTER_H

#include <SDL2/SDL.h>

class upftii_Fight;

enum upftii_Action {
  NONE,
  MOVE_LEFT,
  MOVE_RIGHT
};

class upftii_Fighter {
  SDL_Texture *sprite;
  SDL_Rect *pos;
  upftii_Action action = NONE; 
public:
  upftii_Fighter(upftii_Fight *fight, const char *spritefile, bool onleft);

  upftii_Fight *fight;

  void move(bool toleft);
  void stop();
  void update();
};

#endif
