#include <iostream>
#include <string>
#include <vector>
#include <limits>

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
    //std::cout << "Players: " <<players.size() << "\n";
}

int getPlayerCount(const std::vector<Player>& players) {
    return players.size();
}

int main() {
    std::cout << "Welcome to Wheel of Fortune! \n";

    int roundNumber;

    std::cout << "Enter number of rounds: " << "\n";

    while(true) {
        std::cin >> roundNumber;

        if (std::cin.fail()) {
        std::cout << "Input must be a number! Try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
        }

        if (roundNumber < 1 || roundNumber > 10) {
            std::cout << "Invalid value. Try again: ";
            continue;
         } 
         std::cout << "Valid number of rounds!\n";

        break;
    }

    std::cout << "Number of rounds: " << roundNumber << "\n";

    std::vector<Player> players;
    
    players.push_back({"Alex", 500});
    players.push_back({"John", 300});

    displayPlayers(players);
    int playerCount = getPlayerCount(players);
    std::cout << "Number of players: " << playerCount << "\n";
    
    return 0;
}