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

        // Vector to store formatted activity messages
        std::vector<std::string> activities;

        // Process each event in the response
        for (const auto& event : jsonResponse) {
            std::string eventType = event.value("type", "Unknown Event");
            std::string repoName = event["repo"].value("name", "Unknown Repository");
            std::string eventDate = event.value("created_at", "Unknown Date");

            // Process different event types
            if (eventType == "PushEvent" && event.contains("payload")) {
                auto commits = event["payload"].value("commits", nlohmann::json::array());
                size_t commitCount = commits.size();
                activities.push_back("Pushed " + std::to_string(commitCount) + " commits to " + repoName + " on " + eventDate);
            }
            else if (eventType == "IssuesEvent" && event.contains("payload")) {
                std::string action = event["payload"].value("action", "Unknown Action");
                if (action == "opened") {
                    activities.push_back("Opened a new issue in " + repoName + " on " + eventDate);
                }
            }
            else if (eventType == "WatchEvent") {
                activities.push_back("Starred " + repoName + " on " + eventDate);
            }
        }

        // Print all formatted activities
        if (activities.empty()) {
            std::cout << "No activities to display.\n";
        } else {
            for (const auto& activity : activities) {
                std::cout << "- " << activity << "\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing API response: " << e.what() << "\n";
    }
}