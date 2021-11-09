#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Item.h"
#include "Tile.h"
#include "GameMaster.h"

class GameMaster;
enum class Attribute;
enum class DamageType;

using namespace std;

class Player{
    public:
        Player();
        ~Player();
        void load_player_data(string playerfile);
        void move(int dx, int dy);
        void pick_up(Item* item);
        void drop(Item* item);
        void equip(Item* item);
        void unequip(Item* item);
        void print_inventory();
        void print_attribute_mods();
        void print_attributes();
        void print_contest_attributes();
        void set_current_tile(Tile* tile);

        void take_damage(int damage, DamageType damage_type);

        int get_hitpoints();
        int get_strength();
        int get_intelligence();
        int get_dexterity();
        int get_wisdom();
        int get_charisma();
        int get_constitution();
        int get_armour();
        int get_inititive();

        double get_cut_res();
        double get_imp_res();
        double get_pi_res();
        double get_cr_res();
        double get_tox_res();
        double get_brn_res();

        Attribute get_attack_style();
        string get_name();

    private:
        string _name;
        int _x;
        int _y;
        Tile* _current_tile;

        int _strength;
        int _dexterity;
        int _intelligence;
        int _wisdom;
        int _charisma;
        int _constitution;
        int _armour;
        int _initative;
        int _hitpoints;

        int _strength_mod;
        int _dexterity_mod;
        int _intelligence_mod;
        int _wisdom_mod;
        int _charisma_mod;
        int _constitution_mod;
        int _initative_mod;

        double _cut_res;
        double _imp_res;
        double _pi_res;
        double _cr_res;
        double _tox_res;
        double _brn_res;

        Attribute _attack_style;
        vector<Item*> _inventory;
        Item* _equiped_head;
        Item* _equiped_torso;
        Item* _equiped_hands;
        Item* _equiped_waist;
        Item* _equiped_legs;
        Item* _equiped_feet;
        Item* _equiped_back;
        friend istream& operator>>(std::istream& inputstream, Player& player);
};