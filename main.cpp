// basic mahjong game
// code by Ryuya


#include <iostream>
#include <map>
#include <array>
#include <random>
#include <ctime>
#include <algorithm> // shuffle


void initialize_tile_names(std::map<std::string, int> tiles) {
    // manzu
    tiles.insert({"1m", 0x11});
    tiles.insert({"2m", 0x12});
    tiles.insert({"3m", 0x13});
    tiles.insert({"4m", 0x14});
    tiles.insert({"5m", 0x15});
    tiles.insert({"6m", 0x16});
    tiles.insert({"7m", 0x17});
    tiles.insert({"8m", 0x18});
    tiles.insert({"9m", 0x19});
    
    // pinzu
    tiles.insert({"1p", 0x21});
    tiles.insert({"2p", 0x22});
    tiles.insert({"3p", 0x23});
    tiles.insert({"4p", 0x24});
    tiles.insert({"5p", 0x25});
    tiles.insert({"6p", 0x26});
    tiles.insert({"7p", 0x27});
    tiles.insert({"8p", 0x28});
    tiles.insert({"9p", 0x29});
    
    // souzu
    tiles.insert({"1s", 0x31});
    tiles.insert({"2s", 0x32});
    tiles.insert({"3s", 0x33});
    tiles.insert({"4s", 0x34});
    tiles.insert({"5s", 0x35});
    tiles.insert({"6s", 0x36});
    tiles.insert({"7s", 0x37});
    tiles.insert({"8s", 0x38});
    tiles.insert({"9s", 0x39});
    
    // honor tiles
    tiles.insert({"E", 0x41});
    tiles.insert({"S", 0x42});
    tiles.insert({"W", 0x43});
    tiles.insert({"N", 0x44});
    tiles.insert({"W", 0x45});
    tiles.insert({"G", 0x46});
    tiles.insert({"R", 0x47});
}


void initialize_wall(std::array<int, 136> &wall, std::map<std::string, int> tiles) {
    int i = 0;
    for (const std::pair<std::string, int> t : tiles) {
        // put 4 copies of each tile into the wall
        wall.at(i++) = t.second;
        wall.at(i++) = t.second;
        wall.at(i++) = t.second;
        wall.at(i++) = t.second;
    }
}


void shuffle_wall(std::array<int, 136> &wall) {
    std::mt19937 rng(std::time(nullptr));
    std::shuffle(wall.begin(), wall.end(), rng);
}


int main() {
    std::map<std::string, int> tile_names; // map tile names to integer values for easier hand completeness calculation
    
    
    std::array<int, 136> wall; // 136 tiles total. 4 of each type of tile.
    std::array<int, 14> hand; // 14 tiles in your hand
    int depth; // how deep into the wall you are
    
    std::cout << "Welcome to mahjong!" << std::endl;
    std::cout << "The objective of the game is to create 4 sets of three sequences or triplets and one pair" << std::endl;
    std::cout << "Type q to quit anytime" << std::endl;
    //std::cout << "Hand: " << std::endl;
    std::cout << "Type the tile to discard" << std::endl;
    
    // game loop
    std::string input;
    while (input != "q") {
        std::cin >> input;
        if (input == "q") {
            std::cout << "Thanks for playing!";
        }
    }

    return 0;
}
