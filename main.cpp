/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Fabio
 *
 * Created on 29 de novembro de 2020, 17:31
 */
#include "utils.h"
#include "world.h"
#include "player.h"
#include "territory.h"
#include "game.h"

/*
 * 
 */
int main(int argc, char** argv) {
    srand (time(NULL));
    
    Game g;
    
    World w(&g);
    
    w.interface();
    
    return 0;
}