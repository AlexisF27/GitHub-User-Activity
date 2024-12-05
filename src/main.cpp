#include <iostream>
#include "./GithubUserActivity/GithubUserActivity.h"
    #include <nlohmann/json.hpp>
    using json = nlohmann::json;

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: github-activity <GitHubUsername>\n";
            return 1;
        }

        std::string userName = argv[1];  

        

        GithubUserActivity githubActivity;

        // Fetch the user's activity from the API
        std::cout << "Fetching activity for user '" << userName << "'...\n";
        std::string response = githubActivity.fetchActivityFromAPI(userName);

        // Process and display the API response
        githubActivity.processAPIResponse(response);

    } catch (const std::exception& e) {
        // Handle errors gracefully
        std::cerr << "An error occurred: " << e.what() << "\n";
        return 1;
    }

    return 0;
}