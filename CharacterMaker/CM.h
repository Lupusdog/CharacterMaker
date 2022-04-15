#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <time.h>
using namespace std;

struct character {
    string name;
    string race;
    string job;
    string feature;
    string personality;
};

int selection();

void charaBuild();

character getProperties(character myChara);

void listProperties();

void initRand();

int dice(int i);

