#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <sstream> 

// Function to generate a random sequence
std::vector<std::string> generateRandomSequence(const std::vector<std::string>& availableInputs, int length) {
    std::vector<std::string> sequence;

    for (int i = 0; i < length; ++i) {
        // Randomly decide whether to create a combination action (e.g., A+X)
        if (rand() % 4 == 0) { // Adjust the probability as needed
            // Randomly select two different inputs from availableInputs
            int firstIndex = rand() % availableInputs.size();
            int secondIndex;
            do {
                secondIndex = rand() % availableInputs.size();
            } while (secondIndex == firstIndex);

            sequence.push_back(availableInputs[firstIndex] + "+" + availableInputs[secondIndex]);
        } else {
            // Randomly select a single input from availableInputs
            sequence.push_back(availableInputs[rand() % availableInputs.size()]);
        }
    }

    return sequence;
}

// Function to perform consoleMonkey testing
void consoleMonkeyTestingRand(const std::vector<std::string>& availableInputs, int numSequences) {
    for (int i = 0; i < numSequences; ++i) {
        // Generate a random sequence
        std::vector<std::string> sequence = generateRandomSequence(availableInputs, rand() % 5 + 1);  // Random sequence length between 1 and 5

        // Randomly choose the pace for the sequence
        int pace = rand() % 30 + 1;  // Random pace between 1ms and 30ms

        // Execute the generated sequence with random pacing
        for (size_t j = 0; j < sequence.size(); ++j) {
            // Print the action with a comma
            std::cout << sequence[j];

            // Print a comma after each action, except for the last action
            if (j < sequence.size() - 1) {
                std::cout << ", ";
            }

            // Introduce random pacing between inputs
            std::this_thread::sleep_for(std::chrono::milliseconds(pace));
        }

        // Print the pace after the sequence
        std::cout << " | Pace: " << pace << "ms" << std::endl;

        // Introduce a random pause between sequences
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 2000 + 1000));  // Random pause between 1000ms and 3000ms
    }
}

int main() {
    // Take user input for available inputs
    std::cout << "Enter available inputs (separated by spaces): ";
    std::vector<std::string> availableInputs;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    while (iss >> input) {
        availableInputs.push_back(input);
    }

    // Take user input for the number of sequences
    std::cout << "Enter the number of sequences: ";
    int numSequences;
    std::cin >> numSequences;

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Perform consoleMonkey testing with user-specified inputs
    consoleMonkeyTestingRand(availableInputs, numSequences);

    return 0;
}