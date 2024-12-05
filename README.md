# GithubUserActivity CLI

## Overview
GithubUserActivity is a command-line application written in C++ that fetches and displays recent public activity for a specified GitHub user. It uses the GitHub API and libcurl for HTTP requests and the nlohmann/json library for JSON parsing.

## Project URL
  ```bash
  https://roadmap.sh/projects/github-user-activity
  ```

## Features
- Fetches recent public activity of any GitHub user.
- Displays the type of event, repository name, associated commit messages (if applicable), and the event date.
- Handles errors gracefully, such as invalid usernames or API failures.
- Processes JSON responses with clean and structured formatting.

## Usage

- Command

  ```bash
  ./GithubUserActivity <GitHub_Username>
  ```

- Example Output

  ```bash
  Fetching activity for user 'AlexisF27'...
  - Event: PushEvent
    Repository: AlexisF27/task_tracker
      Commit: Initial commit
      Commit: Added README
    Date: 2024-12-03T21:54:02Z
  - Event: IssuesEvent
    Repository: AlexisF27/task_tracker
    Date: 2024-12-03T21:53:31Z
  ```


# Implementation Details
## Key Components
1. GithubUserActivity Class:
   - Manages user interactions, API calls, and response processing.
   - Core methods:
     - fetchActivityFromAPI: Makes an HTTP GET request to the GitHub API.
     - processAPIResponse: Parses and formats the JSON response.
2. HTTPClient Class:
   - Handles HTTP GET requests using libcurl.
   - Implements callback functions for response handling.
3. JSON Parsing:
   - Uses nlohmann/json to parse the API response.
   - Extracts relevant details such as event type, repository name, and commit messages.
  
# Dependencies
1. libcurl:
  - For making HTTP GET requests.
  - Libcurl Documentation
2. nlohmann/json:
  - For JSON parsing.
  - JSON for Modern C++ GitHub

# Build Instructions
-  Clone the repository:
  
```bash
git clone <repository-url>
cd GithubUserActivity
```

-  Create a build directory:

```bash
git clone <repository-url>
cd GithubUserActivity
```

-  Run cmake and build:

```bash
cmake ..
make
```

-  Run the application:
  
```bash
./GithubUserActivity <GitHub_Username>
```
