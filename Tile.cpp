#include "Tile.h"

using namespace std;

void Tile::remove_item(Item* item){
    auto c = find(_inventory.begin(), _inventory.end(), item);
	if(c != _inventory.end()) {
		_inventory.erase(c);
	} else {
		printf("Cannot remove from tile.\n");
	}
}

void Tile::add_item(Item* item){
    _inventory.push_back(item);
}

void Tile::print_inventory(){
    for(auto item: _inventory){
        cout << item->get_name() << " ";
    }
    cout << endl;
}