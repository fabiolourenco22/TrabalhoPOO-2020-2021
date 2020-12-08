/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   player.cpp
 * Author: Fabio
 * 
 * Created on 1 de dezembro de 2020, 18:26
 */

#include "player.h"

Player::Player(int forcaI) {
    forca = forcaI;
    points = 0;
    items = gold = 0;
    storage = bank = 3;
    playerT.push_back(new Territory("home"));
}

void Player::listaPlayerT() {
    if (playerT.empty()) {
        cout << "O jogador nao tem territorios!\n";
    } else {
        cout << "\nOuro: " << this->getGold() << "\tItems: " << this->getItems()<< endl;
        for (int i = 0; i < playerT.size(); i++) {
            cout << "\nNome: " << playerT[i]->getName();
            cout << "\tResistencia: " << playerT[i]->getResistance();
            
        }
    }
    
    cout << "\n";

}

vector<Territory*> Player::addTerritory(Player* p, string nameT, vector<Territory*> territorios, int *res) {
    string type;
    int sorte = (rand() % 6) + 1;
    vector<Territory*> aux = territorios;

    cout << "Forca do imperio: " << p->getForca() + sorte << endl;

    for (int i = 0; i < aux.size(); i++) {
        if (nameT == aux[i]->getName()) {
            if (p->getForca() + sorte >= aux[i]->getResistance()) {
                playerT.push_back(aux[i]);
                
                type = aux[i]->getType();
                t->decreaseTerritory(type);
                aux.erase(aux.begin() + i);
                *res = 1;

                return aux;
            }
        }
    }
    

}

void Player::turnEarnings(Player* p){
    cout << "\nOuro :" << p->getGold();
    cout << "\nItens: " << p->getItems();
    cout << "\nArmazem: " << p->getStorage();
    cout << "\nBanco :" << p->getBank() << endl;
    
    for(int i = 0; i < playerT.size(); i++){
        cout << "\nOuro a receber: " << playerT[i]->getGold();
        cout << "Itens a receber: " << playerT[i]->getItems() << endl;
        if(p->getGold() + playerT[i]->getGold() <= p->getBank()){
            p->earnGold(playerT[i]->getGold());
            cout << "\nOuro adicionado!\n";
        }else{
            cout << "\nO cofre nao tem capacidade para mais ouro!\n";
        }
        
        if(p->getItems() + playerT[i]->getItems() <= p->getStorage()){
            p->earnItems(playerT[i]->getItems());
            cout << "\nItens adicionados!\n";
        }else{
            cout << "\nO armazem nao tem espaco para mais itens!\n";
        }
    }

}