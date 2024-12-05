#include <iostream>
#include "./GithubUserActivity/GithubUserActivity.h"

int main() {
    try {
        // Create an instance of GithubUserActivity
        GithubUserActivity activityFetcher;

        // Test with a valid GitHub username
        std::string userName = "AlexisF"; // Replace with a valid username
        std::string response = activityFetcher.fetchActivityFromAPI(userName);

        // Print the response to verify output
        std::cout << "API Response for user '" << userName << "':\n" << response << std::endl;

    } catch (const std::exception& e) {
        // Handle any errors
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
