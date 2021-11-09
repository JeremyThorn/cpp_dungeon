#include "Player.h"

using namespace std;

istream& operator>>(istream& is, Player& player);

Player::~Player(){

}

Player::Player(){
    _x = 0;
    _y = 0;
    _current_tile = nullptr;
    _strength = 0;
    _dexterity = 0;
    _intelligence = 0;
    _wisdom = 0;
    _charisma = 0;
    _constitution = 0;
    _armour = 0;
    _initative = 0;
    _hitpoints = 100;

    _strength_mod = 0;
    _dexterity_mod = 0;
    _intelligence_mod = 0;
    _wisdom_mod = 0;
    _charisma_mod = 0;
    _constitution_mod = 0;
    _initative_mod = 0;

    _cut_res = 0;
    _imp_res = 0;
    _pi_res = 0;
    _cr_res = 0;
    _tox_res = 0;
    _brn_res = 0;

    _attack_style = Attribute::STR;
    _equiped_head = nullptr;
    _equiped_torso = nullptr;
    _equiped_hands = nullptr;
    _equiped_waist = nullptr;
    _equiped_legs = nullptr;
    _equiped_feet = nullptr;
    _equiped_back = nullptr;
}

void Player::load_player_data(string playerfile){
    ifstream file(playerfile);
    file >> *this;
    file.close();
}

void Player::pick_up(Item* item){
    _inventory.push_back(item);
    _current_tile->remove_item(item);
}

void Player::drop(Item* item){
    _inventory.erase(remove(_inventory.begin(), _inventory.end(), item), _inventory.end());
    _current_tile->add_item(item);
}

void Player::equip(Item* item){
    if(find(_inventory.begin(), _inventory.end(), item) != _inventory.end()){
        char slot = item->get_equiped_slot();
        _inventory.erase(remove(_inventory.begin(), _inventory.end(), item), _inventory.end());
        _strength_mod += item->get_strength_mod();
        _dexterity_mod += item->get_dexterity_mod();
        _intelligence_mod += item->get_intelligence_mod();
        _wisdom_mod += item->get_wisdom_mod();
        _charisma_mod += item->get_charisma_mod();
        _constitution_mod += item->get_constitution_mod();

        _cut_res += item->get_cut_res();
        _imp_res += item->get_imp_res();
        _pi_res += item->get_pi_res();
        _cr_res += item->get_cr_res();
        _tox_res += item->get_tox_res();
        _brn_res += item->get_brn_res();

        switch(slot){
            case 's':
                _equiped_head = item;
                break;
            case 't':
                _equiped_torso = item;
                break;
            case 'h':
                _equiped_hands = item;
                break;
            case 'w':
                _equiped_waist = item;
                break;
            case 'l':
                _equiped_legs = item;
                break;
            case 'f':
                _equiped_feet = item;
                break;
            case 'b':
                _equiped_back = item;
                break;
        }
    }
}

void Player::unequip(Item* item){
    char slot = item->get_equiped_slot();
    _inventory.push_back(item);
    _strength_mod -= item->get_strength_mod();
    _dexterity_mod -= item->get_dexterity_mod();
    _intelligence_mod -= item->get_intelligence_mod();
    _wisdom_mod -= item->get_wisdom_mod();
    _charisma_mod -= item->get_charisma_mod();
    _constitution_mod -= item->get_constitution_mod();

    _cut_res -= item->get_cut_res();
    _imp_res -= item->get_imp_res();
    _pi_res -= item->get_pi_res();
    _cr_res -= item->get_cr_res();
    _tox_res -= item->get_tox_res();
    _brn_res -= item->get_brn_res();
        
    switch(slot){
        case 's':
            _equiped_head = nullptr;
            break;
        case 't':
            _equiped_torso = nullptr;
            break;
        case 'h':
            _equiped_hands = nullptr;
            break;
        case 'w':
            _equiped_waist = nullptr;
            break;
        case 'l':
            _equiped_legs = nullptr;
            break;
        case 'f':
            _equiped_feet = nullptr;
            break;
        case 'b':
            _equiped_back = nullptr;
            break;
    }
    
}

void Player::print_inventory(){
    for(auto item: _inventory){
        cout << item->get_name() << " ";
    }
    cout << endl;
}

void Player::print_attribute_mods(){
    cout << _strength_mod << " " << _dexterity_mod << " "  << _intelligence_mod << " "  << _wisdom_mod << " "  << _charisma_mod << " "  << _constitution_mod << " "  << endl;
}

void Player::print_attributes(){
    cout << _strength << " " << _dexterity << " "  << _intelligence << " "  << _wisdom << " "  << _charisma << " "  << _constitution << " "  << endl;
}

void Player::print_contest_attributes(){
    cout << _strength + _strength_mod << " " << _dexterity + _dexterity_mod << " "  << _intelligence + _intelligence_mod << " "  << _wisdom + _wisdom_mod << " "  << _charisma + _charisma_mod << " "  << _constitution + _constitution_mod << " "  << endl;
}

void Player::set_current_tile(Tile* tile){
    _current_tile = tile;
}

int Player::get_hitpoints(){
    return _hitpoints;
}

int Player::get_strength(){
    return _strength + _strength_mod;
}

int Player::get_dexterity(){
    return _dexterity + _dexterity_mod;
}

int Player::get_intelligence(){
    return _intelligence + _intelligence_mod;
}

int Player::get_charisma(){
    return _charisma + _charisma_mod;
}

int Player::get_constitution(){
    return _constitution + _constitution_mod;
}

int Player::get_wisdom(){
    return _wisdom + _wisdom_mod;
}

int Player::get_armour(){
    return _armour;
}

Attribute Player::get_attack_style(){
    return _attack_style;
}

string Player::get_name(){
    return _name;
}

int Player::get_inititive(){
    return _initative;
}

double Player::get_cut_res(){
    return _cut_res;
}
double Player::get_cr_res(){
    return _cr_res;
}
double Player::get_imp_res(){
    return _imp_res;
}
double Player::get_pi_res(){
    return _pi_res;
}
double Player::get_tox_res(){
    return _tox_res;
}
double Player::get_brn_res(){
    return _brn_res;
}

void Player::take_damage(int damage, DamageType damage_type){
    double damage_multiplier;
    switch (damage_type){
        case DamageType::CUT:
            damage_multiplier = _cut_res;
            break;
        case DamageType::CR:
            damage_multiplier = _cr_res;
            break;
        case DamageType::IMP:
            damage_multiplier = _imp_res;
            break;
        case DamageType::PI:
            damage_multiplier = _pi_res;
            break;
        case DamageType::BRN:
            damage_multiplier = _brn_res;
            break;
        case DamageType::TOX:
            damage_multiplier = _tox_res;
            break;
    }

    double damage_taken = (int)(((double)damage / 100) * damage_multiplier );
    _hitpoints -=  damage_taken;

    cout << _name << " took " << damage_taken << " damage." << endl;;
    
    if (_hitpoints <= 0){
        this->~Player();
    }
}

istream& operator>>(istream& is, Player& player)
    {
        string line;
        getline(is, line);

        istringstream iss(line);

        iss >> player._name;
        iss >> player._strength;
        iss >> player._dexterity;
        iss >> player._intelligence;
        iss >> player._wisdom;
        iss >> player._charisma;
        iss >> player._constitution;
        iss >> player._armour;

        return is;
    }