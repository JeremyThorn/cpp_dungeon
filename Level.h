#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Level{
    public:
        void load(string fileName);
        void print();
    private:
        vector<string> _level;
};