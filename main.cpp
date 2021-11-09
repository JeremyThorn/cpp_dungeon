#include <iostream>
#include <cstdlib>
#include "Level.h"
#include "GameMaster.h"
#include "Item.h"
#include "Player.h"
#include "Tile.h"

using namespace std;

int main()
{
    Item hat;
    Player barry;
    barry.load_player_data("players/barry.playerfile");
    hat.load_item_data("items/hat.itemfile");

    GameMaster gm;
    gm.init();

    Tile barrys_house;

    hat.set_name("Barry's Hat");

    barry.set_current_tile(&barrys_house);

    barrys_house.add_item(&hat);
    cout << "In barry's hut, there is ";
    barrys_house.print_inventory();
    cout << "In barry's inventory, there is ";
    barry.print_inventory();
    cout << "Now barry will pick up his hat. " << endl;
    barry.pick_up(&hat);
    cout << "In barry's hut, there is ";
    barrys_house.print_inventory();
    cout << "In barry's inventory, there is ";
    barry.print_inventory();
    cout << "These are barrys attributes. " << endl;
    barry.print_attributes();
    cout << "Now barry will equip his hat. " << endl;
    barry.equip(&hat);
    cout << "These are barrys attributes. " << endl;
    barry.print_contest_attributes();
    cout << "Barry will have a contest! " << endl;
    ContestResults res = gm.contest(&barry, Attribute::DEX, 75);
    switch(res){
        case ContestResults::PASS:
            cout << "barry passed!" << endl;
            break;
        case ContestResults::FAIL:
            cout << "barry did not pass :c" << endl;
            cout << "Now barry will take damage! " << endl;
            
            barry.take_damage(70, DamageType::BRN);
            break;
    }


    cout << "Now barry will unequip his hat. " << endl;
    barry.unequip(&hat);
    cout << "These are barrys attributes. " << endl;
    barry.print_contest_attributes();

    return 0;
}