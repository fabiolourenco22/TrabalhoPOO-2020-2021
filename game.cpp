/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.cpp
 * Author: Fabio
 * 
 * Created on 29 de novembro de 2020, 17:33
 */

#include "game.h"

void Game::adicionaTerritorio(string nome, string tam) {
    stringstream ss(tam);
    int quant = 0;
    ss >> quant;

    for (int i = 0; i < quant; i++) {
        territorios.push_back(new Territory(nome));
    }
}

void Game::listaTerritorios() {
    cout << "Total de territorios: " << territorios.size() << endl;

    for (int i = 0; i < territorios.size();
            i++) {
        cout << "Tipo: " << territorios[i]->getType();
        cout << "\tNome: " << territorios[i]->getName();
        cout << "\tResistencia: " << territorios[i]->getResistance();
        cout << "\tItems: " << territorios[i]->getItems();
        cout << "\tOuro: " << territorios[i]->getGold() << endl;
    }
}

void Game::verificaTurnos() {
    for (int i = 0; i < territorios.size(); i++) {

        if(territorios[i]->getType() == "planicie"){
            if(getYear() == 1){
                territorios[i]->setItems(2);
            }
        }
        
        if(territorios[i]->getType() == "mina"){
            if(getTurn() >= 0 && getTurn() <= 2){
                territorios[i]->setGold(1);
            }else if(getTurn() >= 3 && getTurn() <= 5){
                territorios[i]->setGold(2);
            }
        }
        
        if(territorios[i]->getType() == "castelo"){
            if(getTurn() >= 0 && getTurn() <= 1){
                territorios[i]->setItems(3);
            }else{
                territorios[i]->setItems(0);
            }
        }
        
        if(territorios[i]->getType() == "pescaria"){
            if(getYear() == 0){
                territorios[i]->setItems(2);
            }else if(getYear() == 1){
                territorios[i]->setItems(4);
            }
        }
    }
}

void Game::setTurn() {
    if(phase == 3){
        if(turn == 5){
            year++;
            phase = 0;
            turn = 0;
        }else{
            turn++;
            phase = 0;
        }
    }else{
        phase++;
    }
}