#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <regex>
#include <dirent.h>



void psum(const char* pdir){

  struct dirent *pDirent;
  DIR *pDir;

  pDir = opendir(pdir);
  if(pDir == NULL){
    printf("Cannot open directory '%s'\n", pdir);
    exit (EXIT_FAILURE);
  }
  int nmb = 0;
  std::vector<std::string> ts;
  while ((pDirent = readdir(pDir))!= NULL) {
    if(std::regex_match(pDirent->d_name, std::regex("(.*)(_fastqc)"))){
    ts.push_back(pDirent->d_name);
    nmb++;}


  }
  closedir(pDir);



  std::ifstream myfile;
  std::string line;
  std::string pp(pdir);
  int i=0,p=ts.size();

  std::vector<std::vector<std::string> > dat;

  for(int i =0; i<p; i++){

    std::vector<std::string> col;
    std::ifstream myfile;
    std::string line;
    std::string filename = pp+"/"+ts[i]+"/fastqc_data.txt";
    myfile.open(filename, std::ios::in);
    while(std::getline(myfile, line)){

      if(std::regex_match(line, std::regex("(>>)(.*)"))&& !std::regex_match(line, std::regex("(>>END_MODULE)(.*)"))){

        col.push_back(line);
      }
    }
    dat.push_back(std::move(col));
  }
std::cout << "file,";
std::cout << "Basic_statistics,";
std::cout << "Per_base_seq_qual,";
std::cout << "Per_tile_seq_qual,";
std::cout << "Per_seq_qual_scores,";
std::cout << "Per_base_seq_content,";
std::cout << "Per_seq_GC_content,";
std::cout << "Per_base_N_content,";
std::cout << "Sequence_Length_Dist,";
std::cout << "Sequence_Duplication_levels,";
std::cout << "Overrepresented_sequences,";
std::cout << "Adapter_Content," << std::endl;

std::string delimiter = "\t";
for(int i=0; i<p;i++){
    std::cout << ts[i] << ",";
  for(int j=0;j<11;j++){
    std::size_t pos = dat[i][j].find(delimiter);
    dat[i][j].erase(0,pos + delimiter.length()); 
    std::cout << dat[i][j] << ",";
  }
  std::cout<<std::endl;
}


}
