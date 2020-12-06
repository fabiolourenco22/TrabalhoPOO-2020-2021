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
#include "utils.h"
#include "territory.h"
#include "game.h"

class Player{
    vector<Territory*> playerT;
    int points;
    int storage;
    int bank;
    
public:
    Player();
    ~Player();
};

#endif /* PLAYER_H */
