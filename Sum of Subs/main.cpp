#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <unordered_set>

//Given a sorted array, find the smallest positive integer
// that is not the sum of a subset of the array


std::priority_queue<int,std::vector<int>,std::greater<int> > smallestPositive(std::vector<int> myinput) {
  std::priority_queue<int,std::vector<int>,std::greater<int> > us;
  std::unordered_set<int> unordered;
  // get size of the vector
  auto size = myinput.size();
  // create binary representation
  //calculate the number of bits
  auto range = (1 << size) - 1;


  // x is the binary value that will increment between 0 and 15
  // y is the positional index for the individual values in the vector
  // that will be added up for each of the 15 combinations
  // y starts at the maximum value of each of the 15 an

  for (int i = 1; i <= range; i++) {
    auto sum = 0;
    std::string binary = std::bitset<32>(i).to_string(); // convert the integer ( 0 - 15) to bitset then to string
    //std::cout << binary << std::endl;
    for (int j = 0; j < size; j++) { // index through each bit position
      // compare the bit value in positions size-2 through 0

         if (binary[31-j]-'0' == 1) { // convert char to int - either 1 or 0
       // printf("adding");
        sum += myinput[j]; // add to sum
      }
     // printf("j:%d myinput[j]: %d binary[31-j]: %d sum %d\n ",j,myinput[j],binary[31-j]-'0',sum );
    }
    unordered.emplace(sum); // put in unordered set to get rid of duplicates
  }
  for(int inunordered:unordered){ // push unordered set into min queue
    us.emplace(inunordered);
  }


  return us; // send it back

}

int main() {

  std::vector myinput {1,2,3,10};

  std::priority_queue<int,std::vector<int>,std::greater<int> > output = smallestPositive(myinput);

 auto temp = 0;

 temp = output.top();
 output.pop();

 while (output.size() > 1) {
   if(output.top() == temp+1){
     output.pop();
     temp++;
   }else if(output.top() != temp+1){
     printf("the smallest positive non sub integer is: %d",temp + 1);
     return 0;
   }
 }

 if(output.size() == 1){
   printf("the smallest positive non sub integer is: %d",output.top());
   return 0;
 }

 return 0;

}
