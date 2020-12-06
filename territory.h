/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   territory.h
 * Author: Fabio
 *
 * Created on 1 de dezembro de 2020, 18:27
 */

#ifndef TERRITORY_H
#define TERRITORY_H
#include "utils.h"

static int numPlanicie = 0;
static int numMontanha = 0;
static int numFortaleza = 0;
static int numMina = 0;
static int numDuna = 0;
static int numCastelo = 0;
static int numRefugio = 0;
static int numPescaria = 0;
static int totalTerritorios = 1;

class Territory{
    string name;
    string type;
    int resistance;
    int items;
    int gold;
    
public:
    Territory(string);
    ~Territory(){}
    
    string getName() const;
    string getType() const;
    int getResistance() const;
    int getItems() const;
    int getGold() const;
    int getPlanicies() const;
    int countTerritorio() const;
    
    void setTerritorio(string, string);
    void printTerritorio(int);
    
    void checkTurn(string);
    
    void setItems(int);
    void setGold(int);
};

#endif /* TERRITORY_H */
