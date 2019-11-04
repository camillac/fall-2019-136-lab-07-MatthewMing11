#include <iostream>
#include <fstream>

int countChar(std::string line, char c){//counter function
  int total=0;
  for(int i=0;i<line.size();i++){
    if(line[i]==c){
      total++;
    }
  }
  return total;
}

int countString(std::string line, std::string s){//counter function
  int total=0;
  for(int i=0;i<line.size();i++){
    if(line.substr(i,s.length())==s){
      total++;
    }
  }
  return total;
}

std::string removeLeadingSpaces(std::string line){//removing spaces function
  std::string result;
  bool start=false;
  for(int i=0;i<line.size();i++){
    if(!isspace(line[i])||start){
      start=true;
      result+=line[i];
    }
  }
  return result;
}
bool match(std::string line){
  int a=-1,b=-1;
  for(int i=0;i<line.size();i++){
    if(line[i]=='{'&&a<0){
      a=i;
    }
    if(line[i]=='}'&&b<0){
      b=i;
    }
  }
  if((a==-1&&b!=-1)||b<a){//case where } comes before {
    return true;
  }
  else if((a!=-1&&b==-1)||a<b){//case where { comes before }(is somewhat important maybe)
    return false;
  }
  return false;
}

// returns the first index of the given string; returns -1 if not found in line
int indexOf(std::string line, std::string s){
  for (int i = 0; i < line.length(); i++){
    if (line.substr(i, s.length()) == s){
      return i;
    }
  }
  return -1;
}

std::string indent(std::string file){//main function
  int ilevel = 0; // num tabs
  int starComment = 0; // checks for */
  int left,right; // number of left braces, number of right braces
  std::string input,result;
  std::ifstream fin(file);
  while(getline(fin,input)){ // iterates through each line

    left = 0;
    right = 0;

    // ------- QUOTES ("") --------

    // subtracts the number of braces in between the first and second quotation mark ("{}")
    int firstIndex = indexOf(input, "\"");
    if (firstIndex >= 0){
      left -= countChar(input.substr(firstIndex, indexOf(input.substr(firstIndex + 1), "\"") - firstIndex), '{');
      right -= countChar(input.substr(firstIndex, indexOf(input.substr(firstIndex + 1), "\"") - firstIndex), '}');
      // std::cout << countChar(input.substr(firstIndex, indexOf(input.substr(firstIndex + 1), "\"") - firstIndex), '}') << std::endl;
      // std::cout << input.substr(indexOf(input, "\"") + 1) << std::endl;
    }

    // ------- STAR COMMENTS (/* AND */) --------
    if (indexOf(input, "*/") >= 0){ // if there is */, ignore braces before end of comment and close starComment
      starComment = 0;
      left -= countChar(input.substr(0, indexOf(input, "/*")), '{');
      right -= countChar(input.substr(0, indexOf(input, "/*")), '}');
    }

    if (starComment == 1){ // if star comment has not been closed, ignore all braces in line
      left-=countChar(input,'{');
      right-=countChar(input,'}');
    }

    else if (indexOf(input, "/*") >= 0){ // else if star comment begins on this line, ignore all braces after
      starComment = 1;
      left -= countChar(input.substr(indexOf(input, "/*")), '{');
      right -= countChar(input.substr(indexOf(input, "/*")), '}');
    }

    // ------- COMMENTS (// AND //) --------

    if (indexOf(input, "//") >= 0){
      left -= countChar(input.substr(indexOf(input, "//")), '{');
      right -= countChar(input.substr(indexOf(input, "//")), '}');
    }

    left+=countChar(input,'{');
    right+=countChar(input,'}');
    if(right>left){
      ilevel-=(right-left);
    }
    if(right==left&&match(input)){
       ilevel-=right;
    }
    for(int i=0;i<ilevel;i++){
      result+='\t';
    }
    result+=removeLeadingSpaces(input)+"\n";
    if(left>right){
    ilevel+=(left-right);
    }
    if(left==right&&match(input)){
       ilevel+=left;
    }
  }
  fin.close();
  return result;
}
