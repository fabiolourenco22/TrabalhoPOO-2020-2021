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

class Game{
    Territory *t;
    vector<Territory*> territorios;
    
    int turn = 0;
    int year = 0;
    int phase = 0;
public:
    Game(){
        cout << "Jogo criado\n";
    }
    ~Game(){
        cout << "Jogo apagado!\n";
    }
    
    int getTurn(){return turn;}
    int getYear(){return year;}
    int getPhase(){return phase;}
    
    void adicionaTerritorio(string, string);
    void listaTerritorios();
    
    void verificaTurnos();
    void setTurn();
};

#endif /* GAME_H */
