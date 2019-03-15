#pragma once

enum Rank {
	Two, //Special case since using the jokers. Is not used for Hearts and Diamonds
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
	Deuce,
	LJoker,
	BJoker,
};

//Each suit is 2 bits
enum Suit {
	Spades,
	Diamonds,
	Hearts,
	Clubs,
};