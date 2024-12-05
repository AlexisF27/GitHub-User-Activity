#ifndef GITHUBUSERACTIVITY_H
#define GITHUBUSERACTIVITY_H

struct GithubUserActivity
{
  std::string userName;
};

class GithubUserActivity {
 public:
  GithubUserActivity();
  // ~GithubUserActivity();
  void readUserName(const std::string& userName);
};


#endif 