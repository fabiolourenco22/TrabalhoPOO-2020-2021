/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   territory.cpp
 * Author: Fabio
 * 
 * Created on 1 de dezembro de 2020, 18:27
 */
#include "territory.h"
#include <iostream>
#include <string>

void Territory::setItems(int it){
    items = it;
}

void Territory::setGold(int g){
    gold = g;
}

string Territory::getName() const {
    return name;
}

string Territory::getType() const{
    return type;
}

int Territory::getResistance() const{
    return resistance;
}

int Territory::getItems() const{
    return items;
}

int Territory::getGold() const{
    return gold;
}

int Territory::getPlanicies() const {
    return numPlanicie;
}
int Territory::getMontanhas() const {
    return numMontanha;
}
int Territory::getFortalezas() const {
    return numFortaleza;
}
int Territory::getMinas() const {
    return numMina;
}
int Territory::getDunas() const {
    return numDuna;
}
int Territory::getCastelos() const {
    return numCastelo;
}
int Territory::getRefugios() const {
    return numRefugio;
}
int Territory::getPescarias() const {
    return numPescaria;
}

int Territory::countTerritorio() const {
    return totalTerritorios;
}

Territory::Territory(string nome) {
    ostringstream oss;
    
    if(nome == "home"){
        type = nome;
        name = nome;
        resistance = 9;
        items = gold = 1;
    }
    
    if (nome == "planicie") {
        oss << nome << numPlanicie + 1;
        
        type = nome;
        name = oss.str();
        resistance = 5;
        items = gold = 1;
        numPlanicie++;
        totalTerritorios++;
    }
    
    if (nome == "montanha") {
        oss << nome << numMontanha + 1;
        
        type = nome;
        name = oss.str();
        resistance = 6;
        items = gold = 0;
        numMontanha++;
        totalTerritorios++;
    }
    
    if (nome == "fortaleza") {
        oss << nome << numFortaleza + 1;

        type = nome;
        name = oss.str();
        resistance = 8;
        items = gold = 0;
        numFortaleza++;
        totalTerritorios++;
    }
    
    if (nome == "mina") {
        oss << nome << numMina + 1;

        type = nome;
        name = oss.str();
        resistance = 5;
        items = 0;
        gold = 3;
        numMina++;
        totalTerritorios++;
    }
    
    if (nome == "duna") {
        oss << nome << numDuna + 1;

        type = nome;
        name = oss.str();
        resistance = 4;
        items = 1;
        gold = 0;
        numDuna++;
        totalTerritorios++;
    }
    
    if (nome == "castelo") {
        oss << nome << numCastelo + 1;

        type = nome;
        name = oss.str();
        resistance = 7;
        items = 0;
        gold = 1;
        numCastelo++;
        totalTerritorios++;
    }
    
    if (nome == "refugio") {
        oss << nome << numRefugio + 1;

        type = nome;
        name = oss.str();
        resistance = 5;
        items = 0;
        gold = 3;
        numRefugio++;
        totalTerritorios++;
    }
    
    if (nome == "pescaria") {
        oss << nome << numPescaria + 1;

        type = nome;
        name = oss.str();
        resistance = 5;
        items = 0;
        gold = 3;
        numPescaria++;
        totalTerritorios++;
    }
}

void Territory::decreaseTerritory(string type){
    if(type == "planicie"){
        numPlanicie--;
    }
    
    if(type == "montanha"){
        numMontanha--;
    }
    if(type == "fortaleza"){
        numFortaleza--;
    }
    if(type == "mina"){
        numMina--;
    }
    if(type == "duna"){
        numDuna--;
    }
    if(type == "castelo"){
        numCastelo--;
    }
    if(type == "refugio"){
        numRefugio--;
    }
    if(type == "pescaria"){
        numPescaria--;
    }
    
    totalTerritorios--;
}