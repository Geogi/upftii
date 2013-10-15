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

#include "fight.hh"
#include "game.hh"
#include "texutils.hh"

void upftii_Fight::init(upftii_Game *game) {
  left = png2tex(this->leftfile, game->ren);
  right = png2tex(this->rightfile, game->ren);
  bg = png2tex(this->bgfile, game->ren);
  int lh, lw, rh, rw;
  SDL_QueryTexture(left, NULL, NULL, &lw, &lh);
  SDL_QueryTexture(right, NULL, NULL, &rw, &rh);
  
  this->lr.x = 50;
  this->lr.y = game->WHEIGHT - lh - 100;
  this->lr.w = lw;
  this->lr.h = lh;
  this->rr.x = game->WWIDTH - rw - 50;
  this->rr.y = game->WHEIGHT - rh - 100;
  this->rr.w = rw;
  this->rr.h = rh;
  this->update(game);
}

void upftii_Fight::update(upftii_Game *game) {
  SDL_RenderCopy(game->ren, this->bg, NULL, NULL);
  SDL_RenderCopy(game->ren, this->left, NULL, &lr);
  SDL_RenderCopy(game->ren, this->right, NULL, &rr);
}
