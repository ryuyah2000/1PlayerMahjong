// basic mahjong game
// code by Ryuya


#include <iostream>
#include <map>
#include <array>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm> // shuffle


// puts 4 copies of each tile into the wall
void initialize_wall(std::array<int, 136> &wall, const std::map<int, std::string> tiles) {
    int i = 0;
    for (std::pair<int, std::string> t : tiles) {
        // put 4 copies of each tile into the wall
        wall.at(i++) = t.first;
        wall.at(i++) = t.first;
        wall.at(i++) = t.first;
        wall.at(i++) = t.first;
    }
}


// shuffles wall
void shuffle_wall(std::array<int, 136> &wall) {
    std::mt19937 rng(std::time(nullptr));
    std::shuffle(wall.begin(), wall.end(), rng);
}


// generates hand from the first 14 tiles of the wall
int generate_hand(std::array<int, 136> wall, std::vector<int> &hand) {
    for (int i = 0; i < 14; ++i) {
        hand.at(i) = wall.at(i);
    }
    return 14;
}


void print_hand(std::vector<int> &hand, const std::map<int, std::string> tile_names) {
    for (int i : hand) {
        std::cout << tile_names.at(i);
    }
    std::cout << std::endl;
}

void sort_hand(std::vector<int> &hand) {
    std::sort(hand.begin(), hand.end());
}


int main() {
    // map tile names to integer values for easier hand completeness calculation
    const std::map<int, std::string> tile_names {
        // manzu
        { 0x11, "1m" },
        { 0x12, "2m" },
        { 0x13, "3m" },
        { 0x14, "4m" },
        { 0x15, "5m" },
        { 0x16, "6m" },
        { 0x17, "7m" },
        { 0x18, "8m" },
        { 0x19, "9m" },
        
        // pinzu
        { 0x21, "1p" },
        { 0x22, "2p" },
        { 0x23, "3p" },
        { 0x24, "4p" },
        { 0x25, "5p" },
        { 0x26, "6p" },
        { 0x27, "7p" },
        { 0x28, "8p" },
        { 0x29, "9p" },
        
        // souzu
        { 0x31, "1s" },
        { 0x32, "2s" },
        { 0x33, "3s" },
        { 0x34, "4s" },
        { 0x35, "5s" },
        { 0x36, "6s" },
        { 0x37, "7s" },
        { 0x38, "8s" },
        { 0x39, "9s" },
        
        // honor tiles
        { 0x41, "E" },
        { 0x42, "S" },
        { 0x43, "W" },
        { 0x44, "N" },
        { 0x45, "Wh" },
        { 0x46, "Gr" },
        { 0x47, "Re" }
    };
    
    
    std::array<int, 136> wall; // 136 tiles total. 4 of each type of tile.
    std::vector<int> hand(14); // 14 tiles in your hand
    int depth; // how deep into the wall you are
    initialize_wall(wall, tile_names);
    
    // print opening message
    std::cout << "Welcome to mahjong!" << std::endl;
    std::cout << "The objective of the game is to create 4 sets of three sequences or triplets and one pair" << std::endl;
    std::cout << "Type q to quit anytime" << std::endl;
    
    // generate wall and starting hand
    shuffle_wall(wall);
    depth = generate_hand(wall, hand);
    
    sort_hand(hand);
    print_hand(hand, tile_names);
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
