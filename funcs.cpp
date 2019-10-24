#include <iostream>

int countChar(std::string line, char c){//counter function
   int total=0;
   for(int i=0;i<line.size();i++){
      if(line[i]==c){
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

}
int main(){//main function
   int ilevel=0;
   int left,right;
   std::string input;
   while(getline(std::cin,input)){
      left=countChar(input,'{');
      right=countChar(input,'}');
      if(right>left){
         ilevel-=(right-left);
      }
      if(right==left&&match(input)){
         ilevel-=right;
      }
      for(int i=0;i<ilevel;i++){
         std::cout<<'\t';
      }
      std::cout<<removeLeadingSpaces(input)<<std::endl;
      if(left>right){
         ilevel+=(left-right);
      }
      if(left==right&&match(input)){
         ilevel+=left;
      }
   }
}
