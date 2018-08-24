#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#define SUM_OP 9998
#define MULT_OP 9999

void sum(std::vector<long long>& l);
void mult(std::vector<long long>& l);
long long maximum(std::vector<long long> l);
long long minimum(std::vector<long long> l);

int main(){
   std::vector<long long> expression;
   std::string line;
   long long number;
   char optr;
   int N;

   std::cin >> N;
   std::cin.ignore();

   for (int i = 0; i < N; i++)
   {
      expression.clear();
      getline(std::cin, line);
      std::stringstream ExLine(line);
      ExLine >> number;
      expression.push_back(number);
      while(ExLine >> optr >> number){
         if (optr == '+'){
            expression.push_back(SUM_OP);
         }else if(optr == '*'){
            expression.push_back(MULT_OP);
         }
         expression.push_back(number);
      }
      std::cout << "The maximum and minimum are " << maximum(expression) << " and " << minimum(expression) << "." << std::endl;
   }
   return 0;
}


long long maximum(std::vector<long long> l){
   sum(l);
   mult(l);
   return l.front();
}

long long minimum(std::vector<long long> l){
   mult(l);
   sum(l);
   return l.front();
}

void mult(std::vector<long long>& l){
   long long aux;
   std::vector<long long>::iterator it;

   for(it = l.begin(); it != l.end(); it++){
      if(*it == MULT_OP){
         if(it > l.begin() && it != l.end()){
            it = l.erase(it);
            if(it > l.begin() && it != l.end()){
               aux = *it;
               it = l.erase(it);
               it--;
               if(it >= l.begin()){
                  *it *= aux;
               }
            }
         }
      }
   }
}

void sum(std::vector<long long>& l){
   long long aux;
   std::vector<long long>::iterator it;

   for(it = l.begin(); it < l.end(); it++){
      if(*it == SUM_OP){
         if(it > l.begin() && it != l.end()){
            it = l.erase(it);
            if(it > l.begin() && it != l.end()){
               aux = *it;
               it = l.erase(it);
               it--;
               if(it >= l.begin()){
                  *it += aux;
               }
            }
         }
      }
   }
}