# GithubUserActivity CLI

## Overview
GithubUserActivity is a command-line application written in C++ that fetches and displays recent public activity for a specified GitHub user. It uses the GitHub API and libcurl for HTTP requests and the nlohmann/json library for JSON parsing.

## Features
- Fetches recent public activity of any GitHub user.
- Displays the type of event, repository name, associated commit messages (if applicable), and the event date.
- Handles errors gracefully, such as invalid usernames or API failures.
- Processes JSON responses with clean and structured formatting.

## Usage
## Command

  ```bash
    ./GithubUserActivity <GitHub_Username>

## Example Output

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
