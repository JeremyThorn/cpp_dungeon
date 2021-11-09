#include "Item.h"

istream& operator>>(istream& is, Item& item);

Item::Item(){
    _name = "hat";
    _strength_mod = 0;
    _dexterity_mod = 0;
    _intelligence_mod = 0;
    _wisdom_mod = 0;
    _charisma_mod = 0;
    _constitution_mod = 0;

    _cut_res = 0;
    _imp_res = 0;
    _pi_res = 0;
    _cr_res = 0;
    _tox_res = 0;
    _brn_res = 0;

    _equiped_slot = 0;

}

void Item::load_item_data(string itemfile){
    ifstream file(itemfile);
    file >> *this;
    file.close();
}

void Item::set_name(string name){
    _name = name;
}

string Item::get_name(){
    return _name;
}

char Item::get_equiped_slot(){
    return _equiped_slot;
}

int Item::get_strength_mod(){
    return _strength_mod;
}
int Item::get_intelligence_mod(){
    return _intelligence_mod;
}
int Item::get_wisdom_mod(){
    return _wisdom_mod;
}
int Item::get_dexterity_mod(){
    return _dexterity_mod;
}
int Item::get_charisma_mod(){
    return _charisma_mod;
}
int Item::get_constitution_mod(){
    return _constitution_mod;
}

double Item::get_cut_res(){
    return _cut_res;
}
double Item::get_cr_res(){
    return _cr_res;
}
double Item::get_imp_res(){
    return _imp_res;
}
double Item::get_pi_res(){
    return _pi_res;
}
double Item::get_tox_res(){
    return _tox_res;
}
double Item::get_brn_res(){
    return _brn_res;
}

bool operator==(const Item& i1, const Item& i2) {
    if(i1._name==i2._name){
        return true;
    }
    else{
        return false;
    }
}

istream& operator>>(istream& is, Item& item)
    {
        string line;
        getline(is, line);

        istringstream iss(line);

        iss >> item._name;
        iss >> item._strength_mod;
        iss >> item._dexterity_mod;
        iss >> item._intelligence_mod;
        iss >> item._wisdom_mod;
        iss >> item._charisma_mod;
        iss >> item._constitution_mod;

        iss >> item._cut_res;
        iss >> item._imp_res;
        iss >> item._pi_res;
        iss >> item._cr_res;
        iss >> item._tox_res;
        iss >> item._brn_res;

        iss >> item._equiped_slot;

        return is;
    }