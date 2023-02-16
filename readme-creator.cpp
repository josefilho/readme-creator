#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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

int main(int argc, char **argv){
  if(argc == 1){

    printHelp();
    return 1;

  } else if(argc == 2){
    
    string arg = argv[1];
    if(arg == "-h" || arg == "--help"){
      printHelp();
      return 0;
    }

  }

  


  return 0;
}

void printHelp(){
  cout << GREEN_BOLD_TERM;
  cout << "Usage:" << endl << RESET_TERM;
  cout << WHITE_TERM <<"\treadme-creator" << CYAN_BOLD_TERM << " [options]" << endl; 
  cout << endl;
  cout << GREEN_BOLD_TERM << "Options:" << endl << RESET_TERM;
  cout << WHITE_TERM << "\t-h | --help" << CYAN_BOLD_TERM << "\t\tShow this help message" << endl;
  cout << WHITE_TERM << "\t-b | --badge" << CYAN_BOLD_TERM << "\t\tBadge type" << endl;
  cout << WHITE_TERM << "\t-c | --color" << CYAN_BOLD_TERM << "\t\tColor to badge" << endl;
  cout << WHITE_TERM << "\t-n | --no-git" << CYAN_BOLD_TERM << "\t\tNo git repository" << endl;
  cout << endl;
}