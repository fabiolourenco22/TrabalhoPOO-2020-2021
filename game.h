/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.h
 * Author: Fabio
 *
 * Created on 29 de novembro de 2020, 17:33
 */
#ifndef GAME_H
#define GAME_H
#include "territory.h"
#include "player.h"

class Player;

class Game{
    Territory *t;
    Player *p;
    vector<Territory*> territorios;
    
    int turn = 0;
    int year = 0;
    int phase = 0;
public:
    Game(){}
    ~Game(){}
    
    int getTurn(){return turn;}
    int getYear(){return year;}
    int getPhase(){return phase;}
    
    void adicionaTerritorio(string, string);
    void listaTerritorios();
    void listaTerritorios(string);
    
    void verificaTurnos();
    void setTurn(Player*);
    
    void conquest(string, Player*);
    
};

#endif /* GAME_H */
