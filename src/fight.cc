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

#include "game.hh"
#include "fight.hh"
#include "fighter.hh"
#include "texutils.hh"

#include <iostream>
upftii_Fight::upftii_Fight(upftii_Game *game) {
  puts(bgfile);
  this->game = game;
  left = new upftii_Fighter(this, leftdir, true);
  right = new upftii_Fighter(this, rightdir, false);

  bg = png2tex(this->bgfile, game->ren, false);
}

void upftii_Fight::update() {
  SDL_RenderCopy(game->ren, bg, NULL, NULL);
  left->update();
  right->update();
}

void upftii_Fight::updateFacing() {
  if ((right->facingleft && left->pos->x > right->pos->x) ||
      (!right->facingleft && left->pos->x < right->pos->x)) {
    left->flip();
    right->flip();
  }
}
