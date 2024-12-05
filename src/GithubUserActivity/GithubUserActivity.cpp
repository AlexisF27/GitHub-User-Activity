#include "GithubUserActivity.h"
#include <iostream>

GithubUserActivity::GithubUserActivity() {

}

void GithubUserActivity::readUserName(const std::string& userName) {

};

std::string GithubUserActivity::fetchActivityFromAPI(const std::string& userName) {
    const std::string url = "https://api.github.com/users/" + userName + "/events";
    
    // Initialize HTTP connection using your networking library (e.g., libcurl).
    // Example: Using pseudocode for HTTP GET
    std::string response;
    bool success = performHttpGet(url, response); // You will implement this function.
    
    if (!success) {
        throw std::runtime_error("Failed to connect to the API.");
    }
    
    return response;
}