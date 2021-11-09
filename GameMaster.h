#pragma once
#include <stdio.h>
#include <random>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include "Level.h"
#include "Player.h"

class Player;

enum class DamageType {CUT, IMP, PI, CR, TOX, BRN};
enum class Attribute {STR, DEX, INT, WIS, CHA, CON};
enum class ContestResults {PASS, FAIL};

class GameMaster{
    public:
        void init();
        void recvInput();
        void runGame();
        int rolld100();
        void combat_round(Player* player1, Player* player2);
        ContestResults contest(Player* player, Attribute attribute, int challenge);

    private:
        int _currentInput;
        bool _run;
        Level _level;
        int _roll100;
        
        
};