# Code Review for Others

## Code Review For Matthew Ming

* I personally don't recommend to use main.cpp as a test case. I think there should be an option for the user to enter a file ath in the main.cpp so user don't have to go through the hassel of changing the file path manually in the test.cpp, although not required by the instructions.
* Logic is reasonable and easy to understand/follow since comments was provided
* Uses brackets even for a single line if statement is a good practice because it is less likely for errors to occur. (I need to avoid the bad habit of not using curly brackets)

//tip: you can simply the code below with this code: return (a==-1&&b!=-1)||b<a);
//explanation: since there is one else if condition in your bool match function, it would be sufficient enough to just use else, and further more you can just return the if condition because it will return true if the condition is true and false otherwise.
   if((a==-1&&b!=-1)||b<a){//case where } comes before {
      return true;
   }
   else if((a!=-1&&b==-1)||a<b){//case where { comes before }(is somewhat important maybe)
      return false;
   }
