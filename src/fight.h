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

#include "game.h"

#ifndef UPFTII_FIGHT
#define UPFTII_FIGHT
class upftii_Fight {
  const char *leftfile = "res/left.png";
  const char *rightfile = "res/right.png";
  const char *bgfile = "res/bg.png";
 public:
  void init(upftii_Game *game);
};
#endif
