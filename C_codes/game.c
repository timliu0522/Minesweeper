

#include <stdbool.h>
#include <stdio.h>
#include "game_core.h"

/*
 * step(c, r, width, heigth) reveales the content of a square with the
 *   coordinates ([c]olumn,[r]ow). The function returns false if the square does
 *   not contain a mine or if ([c],[r]) has been stepped on before.
 * effects: sets map at ([c],[r]) accordingly.
 */
bool step(const int c, const int r, const int width, const int height) {
  if (c < 0 || r < 0 || c >= width || r >= height) {
    return false;
  }
  int i = map[r*width + c];
  if (i != UNKNOWN) {
    return false;
  } else if (mine_at(c,r)) {
    map[r*width + c] = MINE;
    return true;
  } else {
    int number = mine_at(c-1,r-1) + mine_at(c-1,r) + mine_at(c-1,r+1) +
      mine_at(c,r-1) + mine_at(c,r+1) + mine_at(c+1,r-1) + mine_at(c+1,r) 
      + mine_at(c+1,r+1);
    map[r*width + c] = number;
    return false;
  }
}

/*
 * step_adv(c, r, width, heigth) reveales the content of a square with
 *   the coordinates ([c]olumn,[r]ow). If the revealed square is not next to a
 *   mine, it reveales also all adjacent fields. The function returns false if
 *   the square does not contain a mine or if ([c],[r]) has been stepped on
 *   before.
 * effects: sets map at ([c],[r]) accordingly.
 */
bool step_adv(const int c, const int r, const int width, const int height) {
  if (c < 0 || r < 0 || c >= width || r >= height) {
    return false;
  }
  int i = map[r*width + c];
  if (i != UNKNOWN) {
    return false;
  } else if (mine_at(c,r)) {
    map[r*width + c] = MINE;
    return true;
  } else {
    int number = mine_at(c-1,r-1) + mine_at(c-1,r) + mine_at(c-1,r+1) +
      mine_at(c,r-1) + mine_at(c,r+1) + mine_at(c+1,r-1) + mine_at(c+1,r) 
      + mine_at(c+1,r+1);
    map[r*width + c] = number;
    if (number == 0) {
      step_adv(c-1,r-1,width,height);
      step_adv(c-1,r,width,height);
      step_adv(c-1,r+1,width,height);
      step_adv(c,r-1,width,height);
      step_adv(c,r+1,width,height);
      step_adv(c+1,r-1,width,height);
      step_adv(c+1,r,width,height);
      step_adv(c+1,r+1,width,height);
    }
    return false;
  }
}

/*
 * mark(c, r, width, heigth) marks or unmarks the square with coordinates
 *   ([c]olumn,[r]ow), i.e., it signals weather this square contains a mine or
 *   not. The function returns true if all squares with mines are marked and
 *   all marked squares contain mines, and false otherwise.
 * effects: sets map at ([c],[r]) accordingly.
 */
bool mark(const int c, const int r, int width, int height) {
  if (c < 0 || r < 0 || c >= width || r >= height) {
    return false;
  }
  int i = map[r*width + c];
  if (i == UNKNOWN) {
    map[r*width + c] = MARKED;
    if (all_marked()) {
      return true;
    } else {
      return false;
    }
  } else if (i == MARKED) {
    map[r*width + c] = UNKNOWN;
    if (all_marked()) {
      return true;
    } else {
      return false;
    }
  } else {
    if (all_marked()) {
      return true;
    } else {
      return false;
    }
  }
}

/*
 * print(width, height) prints the current map to the console. Unexplored
 *   squares are represented by '_ ', marked squares by 'P ', and mines by 'X '.
 * effects: writes to the console
 */
void print(int width, int height) {
  for (int r = 0; r < height; ++r) {
    for (int c = 0; c < width; ++c) {
      int i = map[r*width + c];
      if (i == UNKNOWN) {
        printf("_");
      } else if (i == MARKED) {
        printf("P");
      } else if (i == MINE) {
        printf("X");
      } else {
        printf("%d",i);
      }
      if (c != width - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}
