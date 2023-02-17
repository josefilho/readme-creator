#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/filesystem.hpp>


using namespace std;

void printHelp();

#if defined(unix) || defined(__unix__) || defined(__unix) || defined(__APPLE__)

#define RED_BOLD_TERM "\033[1;31m"
#define GREEN_BOLD_TERM "\033[1;32m"
#define YELLOW_BOLD_TERM "\033[1;33m"
#define BLUE_BOLD_TERM "\033[1;34m"
#define MAGENTA_BOLD_TERM "\033[1;35m"
#define CYAN_BOLD_TERM "\033[1;36m"
#define WHITE_BOLD_TERM "\033[1;37m"
#define WHITE_TERM "\033[0;37m"
#define RESET_TERM "\033[0m"

#endif

string githubBadges(){
  string madeBy;
  string repoSize;
  string topLang;

  string user;
  string repo;

  cout << MAGENTA_BOLD_TERM << "Github user: " << RESET_TERM;
  getline(cin, user);

  cout << MAGENTA_BOLD_TERM << "Github repository: " << RESET_TERM;
  getline(cin, repo);

  repoSize = "https://img.shields.io/github/repo-size/" + user + "/" + repo + "?color=7159c1&style=for-the-badge";
  topLang = "https://img.shields.io/github/languages/top/" + user + "/" + repo + "?color=7159c1&style=for-the-badge";
  madeBy = "https://img.shields.io/badge/Made%20by-" + user + "-7159c1?style=for-the-badge";

  repoSize = "<img src=\"" + repoSize + "\" />";
  topLang = "<img src=\"" + topLang + "\" />";
  madeBy = "<img src=\"" + madeBy + "\" />";

  return "<center>\n\t" + madeBy + "\n\t" + repoSize + "\n\t" + topLang + "\n" + "</center>";
}

int main(int argc, char **argv){
  string path;
  bool git = true;

  if(argc >= 2) {
    if(argc == 2){
      string arg = argv[1];
      if(arg == "-h" || arg == "--help"){
        printHelp();
        return 0;
      } else if (arg == "-n" || arg == "--no-git"){
        git = false;  
      } else {
        cout << RED_BOLD_TERM << "Error: " << RESET_TERM << "Invalid argument" << endl;
        printHelp();
      }
      return 1;
    } else {
      cout << RED_BOLD_TERM << "Error: " << RESET_TERM << "Too many arguments" << endl;
      printHelp();
      return 1;
    }
  }


  string filePath = (string)get_current_dir_name() + "/README.md";

  cout << GREEN_BOLD_TERM << "File will be saved in: " << RESET_TERM;
  cout << filePath << endl;

  string gitRepo;

  if(git){
    cout << GREEN_BOLD_TERM << "Git repository: " << RESET_TERM;
    getline(cin, gitRepo);

    // @ TODO: Check if git repository is valid
  }

  string author;
  string title;
  string description;
  vector<string> subtitles;
  vector<string> subDescriptions;

  cout << GREEN_BOLD_TERM << "Author: " << RESET_TERM;
  getline(cin, author);
  
  cout << GREEN_BOLD_TERM << "Title: " << RESET_TERM;
  getline(cin, title);

  cout << GREEN_BOLD_TERM << "Description: " << RESET_TERM;
  getline(cin, description);

  cout << GREEN_BOLD_TERM << "Subtitles: " << RESET_TERM;
  string subtitle;
  while(true){
    getline(cin, subtitle);
    if(subtitle == "") break;
    subtitles.push_back(subtitle);
  }

  cout << GREEN_BOLD_TERM << "Subdescriptions: " << RESET_TERM;
  string subDescription;
  for(size_t i = 0; i < subtitles.size(); i++){
    cout << CYAN_BOLD_TERM << "Subdescription(" 
         << MAGENTA_BOLD_TERM << subtitles[i] 
         << CYAN_BOLD_TERM <<"): " << RESET_TERM;
    getline(cin, subDescription);
    subDescriptions.push_back(subDescription);
  }

  ofstream file(filePath);
  file << "<center>" << endl;
  file << "# " << title << endl;
  
  if(git){
    file << githubBadges() << endl;
  }
  

  file << "</center>" << endl;
  file << description << endl;
  file << endl;

  file << "## Table of Contents" << endl;
  file << endl;
  for_each(subtitles.begin(), subtitles.end(), [&](string subtitle){
    file << "* [" << subtitle << "](#" << subtitle << ")" << endl;
  });
  file << endl;

  for(size_t i = 0; i < subtitles.size(); i++){
    file << "## " << subtitles[i] << endl;
    file << endl;
    file << subDescriptions[i] << endl;
    file << endl;
  }

  file << endl << "---" << endl;
  file << "Made with <3 by " << author << endl;

  return 0;
}

void printHelp(){
  cout << GREEN_BOLD_TERM;
  cout << "Usage:" << endl << RESET_TERM;
  cout << WHITE_TERM <<"\treadme-creator" << CYAN_BOLD_TERM << " [options]" << endl; 
  cout << endl;
  cout << GREEN_BOLD_TERM << "Options:" << endl << RESET_TERM;
  cout << WHITE_TERM << "\t-h | --help" << CYAN_BOLD_TERM << "\t\tShow this help message" << endl;
  cout << WHITE_TERM << "\t-n | --no-git" << CYAN_BOLD_TERM << "\t\tNo git repository" << endl;
  cout << endl;
}