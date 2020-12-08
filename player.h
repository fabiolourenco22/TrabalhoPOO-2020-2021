/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   player.h
 * Author: Fabio
 *
 * Created on 1 de dezembro de 2020, 18:26
 */


#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"

class Game;

class Player{
    Game *g;
    Territory *t;
    vector<Territory*> playerT;
    int forca;
    int points;
    int items;
    int gold;
    int storage;
    int bank;
    
public:
    Player(int);
    ~Player(){}
    
    int getForca() const{
        return forca;
    }
    int getStorage() const{
        return storage;
    }
    int getBank() const{
        return bank;
    }
    int getGold() const{
        return gold;
    }
    int getItems() const{
        return items;
    }
    
    void earnGold(int goldEarnings){
        gold += goldEarnings;
    }
    void earnItems(int itemEarnings){
        items += itemEarnings;
    }
    
    void listaPlayerT();
    vector<Territory*> addTerritory(Player* p, string nameT, vector<Territory*> territorios, int *res);
    void turnEarnings(Player* p);
};

#endif /* PLAYER_H */