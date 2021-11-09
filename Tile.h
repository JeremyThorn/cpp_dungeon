#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Item.h"

using namespace std;

class Tile{
    public:
        void remove_item(Item* item);
        void add_item(Item* item);
        void print_inventory();
    private:
        vector<Item*> _inventory;
        

};