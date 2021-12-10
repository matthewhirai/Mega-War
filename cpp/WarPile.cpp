#include <iostream>
#include "../headers/WarPile.h"
using namespace std;

Card WarPile::deal() {
  return remove();
}