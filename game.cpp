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

void Game::listaTerritorios(){
    if(territorios.empty()){
        cout << "\nNao existem territorios!\n";
    }else{
        cout << "\nTerritorios existentes: " << t->countTerritorio() << endl;
        cout << "Planicies: " << t->getPlanicies() << endl;
        cout << "Montanhas: " << t->getMontanhas() << endl; 
        cout << "Fortalezas: " << t->getFortalezas() << endl; 
        cout << "Minas: " << t->getMinas() << endl; 
        cout << "Dunas: " << t->getDunas() << endl; 
        cout << "Castelos: " << t->getCastelos() << endl; 
        cout << "Refugios: " << t->getRefugios() << endl; 
        cout << "Pescarias: " << t->getPescarias() << endl; 
    }
    
    cout << "\n";
}

void Game::listaTerritorios(string nomeT) {
    
    if(territorios.empty()){
        cout << "\nNao existem territorios!\n";
    }else{
        for(int i = 0; i < territorios.size(); i++){
            if(nomeT == territorios[i]->getName()){
                cout << "Nome: " << territorios[i]->getName() << endl;
                cout << "Resistencia: " << territorios[i]->getResistance() << endl;
                cout << "Producao: " << territorios[i]->getItems() << endl;
                cout << "Ouro: " << territorios[i]->getGold() << endl;
            }
        }
    }
    
    cout << "\n";
}

void Game::verificaTurnos() {
    for (int i = 0; i < territorios.size(); i++) {

        if (territorios[i]->getType() == "planicie") {
            if (getYear() == 1) {
                territorios[i]->setItems(2);
            }
        }

        if (territorios[i]->getType() == "mina") {
            if (getTurn() >= 0 && getTurn() <= 2) {
                territorios[i]->setGold(1);
            } else if (getTurn() >= 3 && getTurn() <= 5) {
                territorios[i]->setGold(2);
            }
        }

        if (territorios[i]->getType() == "castelo") {
            if (getTurn() >= 0 && getTurn() <= 1) {
                territorios[i]->setItems(3);
            } else {
                territorios[i]->setItems(0);
            }
        }

        if (territorios[i]->getType() == "pescaria") {
            if (getYear() == 0) {
                territorios[i]->setItems(2);
            } else if (getYear() == 1) {
                territorios[i]->setItems(4);
            }
        }
    }
}

void Game::setTurn(Player *p) {
    if (phase == 3) {
        if (turn == 5) {
            year++;
            phase = 0;
            turn = 0;
        } else {
            turn++;
            p->turnEarnings(p);
            phase = 0;
        }
    } else {
        phase++;
    }
}

void Game::conquest(string nameT, Player* p) {
    int res;
    
    territorios = p->addTerritory(p, nameT, territorios, &res);
    
    if(res == 1){
        cout << "\nConquistou com sucesso!\n";
        setTurn(p);
    }else{
        cout << "\nNao conseguiu conquistar!\n";
    }
    cout << "\n";
}