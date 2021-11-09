#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Item{
    public:
        Item();
        void load_item_data(string itemfile);
        string get_name();
        char get_equiped_slot();
        void set_name(string name);
        int get_strength_mod();
        int get_dexterity_mod();
        int get_intelligence_mod();
        int get_wisdom_mod();
        int get_charisma_mod();
        int get_constitution_mod();
        double get_cut_res();
        double get_imp_res();
        double get_pi_res();
        double get_cr_res();
        double get_tox_res();
        double get_brn_res();
    private:
        string _name;
        int _strength_mod;
        int _dexterity_mod;
        int _intelligence_mod;
        int _wisdom_mod;
        int _charisma_mod;
        int _constitution_mod;
        double _cut_res;
        double _imp_res;
        double _pi_res;
        double _cr_res;
        double _tox_res;
        double _brn_res;
        char _equiped_slot;
        friend bool operator==(const Item& i1, const Item& i2);
        friend istream& operator>>(istream& is, Item& item);
};