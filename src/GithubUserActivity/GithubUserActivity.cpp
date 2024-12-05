#include "GithubUserActivity.h"
#include "../HTTPClient/HTTPClient.h"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp> // Include the JSON libra


GithubUserActivity::GithubUserActivity() {
    // Constructor logic (if needed)
}

GithubUserActivity::~GithubUserActivity() {
    // Destructor logic (if needed)
}
void GithubUserActivity::readUserName(const std::string& userName) {

};

std::string GithubUserActivity::fetchActivityFromAPI(const std::string& userName) {
    const std::string url = "https://api.github.com/users/" + userName + "/events";
    HTTPClient httpClient;
    std::string response;
    try {
        response = httpClient.performHttpGet(url);
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to fetch user activity: " + std::string(e.what()));
    }
    return response;
}

void GithubUserActivity::processAPIResponse(const std::string& response) {
    try {
        // Parse the JSON response
        auto jsonResponse = nlohmann::json::parse(response);

        if (jsonResponse.empty()) {
            std::cout << "No recent public activity found for this user.\n";
            return;
        }



        

        // Iterate through each event and extract details
        for (const auto& event : jsonResponse) {
            std::string eventType = event.value("type", "Unknown Event");
            std::string repoName = event["repo"].value("name", "Unknown Repository");

            std::cout << "- Event: " << eventType << "\n";
            std::cout << "  Repository: " << repoName << "\n";

            // If it's a PushEvent, print commit messages
            if (eventType == "PushEvent" && event.contains("payload")) {
                auto commits = event["payload"].value("commits", nlohmann::json::array());
                for (const auto& commit : commits) {
                    std::string commitMessage = commit.value("message", "No commit message");
                    std::cout << "    Commit: " << commitMessage << "\n";
                }
            }

            std::cout << "  Date: " << event.value("created_at", "Unknown Date") << "\n\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing API response: " << e.what() << "\n";
    }
}