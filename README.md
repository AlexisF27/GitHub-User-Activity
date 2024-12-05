# GithubUserActivity CLI

## Overview
GithubUserActivity is a command-line application written in C++ that fetches and displays recent public activity for a specified GitHub user. It uses the GitHub API and libcurl for HTTP requests and the nlohmann/json library for JSON parsing.

## Features
- Fetches recent public activity of any GitHub user.
- Displays the type of event, repository name, associated commit messages (if applicable), and the event date.
- Handles errors gracefully, such as invalid usernames or API failures.
- Processes JSON responses with clean and structured formatting.
