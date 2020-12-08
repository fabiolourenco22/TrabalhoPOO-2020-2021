/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   world.cpp
 * Author: Fabio
 * 
 * Created on 1 de dezembro de 2020, 17:27
 */
#include "utils.h"
#include "world.h"
#include "game.h"
#include <sstream>
#include <valarray>

World::World() {
    cout << "Mundo criado!\n";
}

void World::execComando(string comando) {
    string cmd;
    stringstream ss(comando);
    ss >> cmd;

    arg = checkArg(comando);

    if (cmd == "carrega") {
        carregaConfig(arg[1]);
    }

    if (cmd == "lista") {
        if (arg.size() == 1) {
            g->listaTerritorios();
        } else {
            if (arg[1] == "player") {
                p->listaPlayerT();
            } else {
                g->listaTerritorios(arg[1]);
            }
        }

    }

    if (cmd == "cria") {
        g->adicionaTerritorio(arg[1], arg[2]);

    }

    if (cmd == "passa") {
        g->setTurn(p);
    }

    if (cmd == "conquista") {
        if (g->getPhase() == 0) {
            g->conquest(arg[1], p);

        } else {
            cout << "\nNao pode conquistar na fase atual!\n";
        }
    }
}

void World::interface() {
    string comando;

    p = new Player(2);

    cout << " ______________________________" << endl;
    cout << "|                              |" << endl;
    cout << "|        CIVILIZATION          |" << endl;
    cout << "|            POO               |" << endl;
    cout << "|        Fabio Lourenco        |" << endl;
    cout << "|          2020/2021           |" << endl;
    cout << " ______________________________" << endl;

    do {
        cout << "Ano: " << g->getYear();
        cout << "\tTurno: " << g->getTurn();
        cout << "\tFase: " << g->getPhase() << endl;
        g->verificaTurnos();
        cout << "Comando: ";
        getline(cin, comando);
        execComando(comando);

    } while (comando.compare("sair"));

    delete(g);
}

void World::carregaConfig(string nomeFich) {
    ifstream myFile;
    string str;

    myFile.open(nomeFich);

    if (myFile.fail()) {
        cerr << "Erro ao abrir o ficheiro!\n";
        exit(1);
    } else {
        cout << "\nO ficheiro " << nomeFich << " foi aberto corretamente!\n";
    }


    while (getline(myFile, str)) {
        execComando(str);
    }

    myFile.close();
}

vector<string> World::checkArg(string str) {
    vector<string> result;
    istringstream ss(str);
    string token;

    while (getline(ss, token, ' ')) {
        result.push_back(token);
    }

    return result;
}