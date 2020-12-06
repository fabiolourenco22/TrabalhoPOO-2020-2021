/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   world.h
 * Author: Fabio
 *
 * Created on 1 de dezembro de 2020, 17:27
 */

#ifndef WORLD_H
#define WORLD_H
#include "game.h"
#include "territory.h"

class Game;
class Territory;

class World{
    Game *g;
    Territory *t;
    vector<string> arg;
    
public:
    World();
    World(Game *game){
        g = game;
    }
    ~World(){
        cout << "Mundo apagado!\n";
    }
    
    void interface();
    void execComando(string);
    void carregaConfig(string);
    void listaTerritorios();
    vector<string> checkArg(string);
    
};

#endif /* WORLD_H */
