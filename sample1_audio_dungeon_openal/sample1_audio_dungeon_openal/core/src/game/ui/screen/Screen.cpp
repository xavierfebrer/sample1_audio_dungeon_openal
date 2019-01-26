#include "../../../../include/Screen.h"
#include "../../../../include/Game.h"

Screen::Screen(Game & g) : game(g), viewManager(game) {
}

Screen::~Screen() {
}
