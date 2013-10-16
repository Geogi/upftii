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

upftii_Fighter::upftii_Fighter(upftii_Fight *fight,
			       const char *spritefile,
			       bool onleft) {
  this->fight = fight;
  this->spritefile = spritefile;
  facingleft = !onleft;

  updateSprite();

  pos = new SDL_Rect();
  pos->x = onleft ? 50 : fight->game->WWIDTH - spr_w - 200;
  pos->y = fight->game->WHEIGHT - spr_h - 100;
  pos->w = spr_w;
  pos->h = spr_h;
}

void upftii_Fighter::updateSprite() {
  sprite = png2tex(spritefile, fight->game->ren, facingleft);
  SDL_QueryTexture(sprite, NULL, NULL, &spr_w, &spr_h);
}

void upftii_Fighter::flip() {
  facingleft = !facingleft;
  updateSprite();
}

void upftii_Fighter::move(bool toleft) {
  action = toleft ? MOVE_LEFT : MOVE_RIGHT;
}

void upftii_Fighter::stop() {
  if (action == MOVE_LEFT || action == MOVE_RIGHT)
    action = NONE;
}

void upftii_Fighter::update() {
  // update fighter
  bool moved = false;
  switch(action) {
  case MOVE_LEFT:
    if(pos->x > 0) {
      pos->x--;
      moved = true;
    }
    break;
  case MOVE_RIGHT:
    if(pos->x < fight->game->WWIDTH - spr_w) {
      pos->x++;
      moved = true;
    }
    break;
  }
  if (moved)
    fight->updateFacing();

  // render
  SDL_RenderCopy(fight->game->ren, sprite, NULL, pos);
}
