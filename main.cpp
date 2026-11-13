#include <iostream>
#include <string>
#include <vector>

struct Player {
    std::string name;
    int score;
};

void displayPlayers(const std::vector<Player>& players) {
    int playerNumber = 1;
    for (const Player& player : players) {
        std::cout << "Player " << playerNumber << " name: " << player.name << "\n";
        std::cout << "Player " << playerNumber << " score: " << player.score << "\n";

        
        playerNumber++;
    }
    std::cout << "Players: " <<players.size() << "\n";
}

int getPlayerCount(const std::vector<Player>& players) {
    return players.size();
}

int main() {
    std::cout << "Welcome to Wheel of Fortune! \n";
    int roundNumber = 5;

    std::cout << "Number of rounds: " << roundNumber << "\n";

    std::vector<Player> players;
    
    players.push_back({"Alex", 500});
    players.push_back({"John", 300});

    displayPlayers(players);
    int playerCount = getPlayerCount(players);
    std::cout << "Number of players: " << playerCount << "\n";
    
    return 0;
}