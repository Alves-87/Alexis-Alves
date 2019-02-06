#pragma
#include <iostream>
#include <vector>
#include <algorithm>

struct cards
{
   char suits;
   int face; 
};

class deck{
     private:
        std::vector<cards> Card;
     public:
        deck();
        deck(deck &a);
        cards Read(int num);
        void suffle();
        *std::vector<cards> Begin(){
            return Card.begin();
        } 
        endvector<cards>* End(){
            return Card.end();
        } 
        void set(std::vector<cards> &a, int num){

            
            if( num == 1)
            {
                std::vector<cards> Sub (Card.begin(),Card.end()-26);
                a = Sub;
                return;
            }
            if( num == 2)
            {
                std::vector<cards> Sub (Card.begin()+25,Card.end());
                 a = Sub;
                 return;
            }
            else
            {
                std::cout << "Error" << std::endl;
            }
        }
};

deck::deck()
{
    int NumCard = 0;
            char suit[4] = {'s','h','d','c'};
            for(int i =0 ; i < 4; ++i)
        {
            for(int j =0 ; j < 13; ++j)
            {
                cards a;
                a.face = j;
                a.suits = suit[i] ;
                Card.push_back(a);
            }
        }
}
deck::deck(deck &a)
{
    std::vector<cards> Sub (a.Begin(),a.End()-26);
    Card = Sub;
}
cards deck::Read(int num)
{
    return Card[num];
}
void deck::suffle()
{
    std::random_shuffle(&Card[0],&Card[52]);
}