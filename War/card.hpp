#pragma once

enum Rank {
	Two, 
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,
	Joker,
};


enum Suit {
	Spades,
	Diamonds,
	Hearts,
	Clubs,
};

enum Color {
    Red,
    Black,
}
class Card{
    Card() = default;

    Card(Rank r, Suit s){
        bits((unsigned)s << 4 | (unsigned)r);
    }

    Rank get_Rank() const {
        return()
    }
};

class RegularCard : Card
{
    public:
        RegularCard(Rank r, Suit s)
            :rank = r, suit = s{}
        Rank get_rank() const   
        {
            return rank;
        }
        Suit get_suit() const 
        {
            return suit;
        }
    private:
        Rank rank;
        Suit suit;
};

class JokerCard : Card 
{
    public:
        JokerCard(Color c)
            : color = c {}
        Color get_color() const
        {
            return color;
        } 
    private:

}
