#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <random>

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

    int playerCount;

    std::cout << "Enter number of players (1-3): ";
    
    while(true) {
        std::cin >> playerCount;

        if (std::cin.fail()) {
            std::cout << "Input must be a number! Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (playerCount < 1 || playerCount > 3) {
            std::cout << "Invalid value. Try again: ";
            continue;
        }

        std::cout << "Valid number of players!\n";

        break;
    }

    std::cout << "Number of players: " << playerCount << "\n";

    std::vector<Player> players;

    for (int i = 0; i < playerCount; i++) {
        std::cout << "Enter name for Player " << i + 1 << ": ";
        
        std::string name;
        std::cin >> name;

        players.push_back({name, 0});
    }

    displayPlayers(players);

    std::map<std::string, std::vector<std::string>> categories;

    categories["FOOD"] = {"PIZZA", "BURGER", "FRENCH FRIES", "CHOCOLATE CAKE", "ICE CREAM"};
    categories["ANIMALS"] = {"DOG", "CAT", "SNAKE", "POLAR BEAR", "CROCODILE"};
    categories["COUNTRIES"] = {"POLAND", "GERMANY", "USA", "SOUTH KOREA", "NEW ZEALAND"};

    //for (const auto& category : categories) {
        //"Map key"
        //std::cout << "Category: " << category.first << "\n";
       // for (const std::string& phrase : category.second) {
       //     std::cout << phrase << "\n";
       // }

       // std::cout << "\n";
    //}

    std::vector<std::string> categoryNames;
    for (const auto& category : categories) {
        categoryNames.push_back(category.first);
    }

    std::cout << "Available categories:\n";
    for (const std::string& name : categoryNames) {
        std::cout << name << "\n";
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < roundNumber; i++) {
        std::cout << "Round " << i + 1 << "\n";
    

        std::uniform_int_distribution<int> categoryDistribution(
            0,
            static_cast<int>(categoryNames.size()) - 1
        );
        int randomCategoryIndex = categoryDistribution(gen);
        std::string randomCategory = categoryNames[randomCategoryIndex];

        std::uniform_int_distribution<int> phraseDistribution(
            0,
            static_cast<int>(categories[randomCategory].size()) - 1
        );

        int randomPhraseIndex = phraseDistribution(gen);

        std::string randomPhrase = categories[randomCategory][randomPhraseIndex];
        //randomPhrase = "PIZZA";
        std::vector<char> hiddenPhrase;

        for (size_t i = 0; i < randomPhrase.size(); i++) {
            if (randomPhrase[i] == ' ') {
                hiddenPhrase.push_back(' ');
            } else {
                hiddenPhrase.push_back('_');
            }
        }

        std::cout << "Random category: " << randomCategory << "\n";
        std::cout << "Random phrase: " << randomPhrase << "\n";
        std::cout << "Hidden phrase: ";


        for (size_t i = 0; i < hiddenPhrase.size(); i++) {
            std::cout << hiddenPhrase[i] << " ";
        }
        std::cout << "\n";

        categories[randomCategory].erase(
            categories[randomCategory].begin() + randomPhraseIndex
        );

        char guessedLetter = 'A';
        std::cout << "Guessed letter: " << guessedLetter << "\n";

        bool letterFound = false;
        int letterCount = 0; 

        int letterValue = 200;

        for (size_t i = 0; i < randomPhrase.size(); i++) {
            if (randomPhrase[i] == guessedLetter) {
                hiddenPhrase[i] = guessedLetter;
                letterFound = true;
                letterCount++;
            } 
        }
        
        if (letterFound) {
            std::cout << "Letter found!\n";
            std::cout << "Updated phrase: ";
            for (size_t i = 0; i < hiddenPhrase.size(); i++) {
                std::cout << hiddenPhrase[i] << " ";   
            }
            std::cout << "\n";

            int pointsEarned = letterValue * letterCount;
            std::cout << "Points earned: " << pointsEarned << "\n";
            players[0].score += pointsEarned;
        } else {
            std::cout << "Letter not found!\n";
            std::cout << "Updated phrase: ";
            for (size_t i = 0; i < hiddenPhrase.size(); i++) {
                std::cout << hiddenPhrase[i] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "Letter Counter: " << letterCount << "\n";
        std::cout << "Player 1 score: " << players[0].score << "\n";


        std::cout << "Remaining phrases in " << randomCategory << ": " << categories[randomCategory].size() << "\n";
    }
    return 0;
}