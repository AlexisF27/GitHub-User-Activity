#include <iostream>
#include "./GithubUserActivity/GithubUserActivity.h"
    #include <nlohmann/json.hpp>
    using json = nlohmann::json;

int main() {
    try {
        // Create an instance of GithubUserActivity
        GithubUserActivity activityFetcher;

        // Test with a valid GitHub username
        std::string userName = "AlexisF27"; // Replace with a valid username
        std::string response = activityFetcher.fetchActivityFromAPI(userName);  // Process and display the API response
        activityFetcher.processAPIResponse(response);

    } catch (const std::exception& e) {
        // Handle any errors
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
