#include "GameMaster.h"

void GameMaster::init(){
    srand (time(NULL));
}

int GameMaster::rolld100(){
    static random_device rd;
    static default_random_engine g(rd());
    static uniform_int_distribution<int> d(1,100);
    static auto rando = bind(d,g);
    return rando();
}

ContestResults GameMaster::contest(Player* player, Attribute attribute, int challenge){
    int player_attribute;
    switch(attribute){
        case Attribute::STR:
            player_attribute = player->get_strength();
            break;
        case Attribute::DEX:
            player_attribute = player->get_dexterity();
            break;
        case Attribute::INT:
            player_attribute = player->get_intelligence();
            break;
        case Attribute::WIS:
            player_attribute = player->get_wisdom();
            break;
        case Attribute::CHA:
            player_attribute = player->get_charisma();
            break;
        case Attribute::CON:
            player_attribute = player->get_constitution();
            break;
    }
    if(player_attribute + rolld100() > challenge){
        return ContestResults::PASS;
    }
    else{
        return ContestResults::FAIL;
    }
}

void GameMaster::combat_round(Player* player1, Player* player2){

    int init_1 = player1->get_inititive();
    int init_2 = player2->get_inititive();
    Attribute attack_style_1 = player1->get_attack_style();
    Attribute attack_style_2 = player2->get_attack_style();

    int ac_1 = player1->get_armour();
    int ac_2 = player2->get_armour();

    if(init_1 > init_2){
        ContestResults res = contest(player1, attack_style_1, ac_2);

    }
    else if(init_2 > init_1){
        contest(player1, attack_style_1, ac_2);

    }
    else{
        contest(player1, attack_style_1, ac_2);
        contest(player2, attack_style_2, ac_1);
    }

    
}

void GameMaster::recvInput(){

}

void GameMaster::runGame(){

}