#include "GithubUserActivity.h"
#include "../HTTPClient/HTTPClient.h"
#include <iostream>
#include <string>

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
    std::cout << "API Response: " << response << "\n";
    // Add JSON parsing logic here
}