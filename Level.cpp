#include "Level.h"


using namespace std;

void Level::load(string fileName){
    ifstream levelInputFile;
    string line;
    levelInputFile.open(fileName);
    while(getline(levelInputFile, line)){
        _level.push_back(line);
    }
    levelInputFile.close();
}

void Level::print(){
    //cout << string(100, ' ') << endl;
    for(int i = 0; i<_level.size(); i++){
        cout << _level[i] << endl;
    }
}
