#ifndef GITHUBUSERACTIVITY_H
#define GITHUBUSERACTIVITY_H
#include <string>



class GithubUserActivity {
  std::string userName;
public:
  GithubUserActivity();
  ~GithubUserActivity();
  void readUserName(const std::string& userName);
  std::string fetchActivityFromAPI(const std::string& userName);
  void processAPIResponse(const std::string& response);
};


#endif 