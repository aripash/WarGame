#include "doctest.h"
#include "DemoGame.hpp"  
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>
#include <string>


using namespace WarGame;
using namespace std;


TEST_CASE("testing throws"){
	Board board(3,3);
	board[pair(1,1)] = new FootSoldier(1);
	CHECK_THROWS(board[pair(1,1)] = new FootSoldier(1));//spawn a new soldier on top of another
	board[pair(0,1)] = new FootSoldier(1);
	CHECK_THROWS(board.move(1, pair(0,1), Board::MoveDIR::Up));//outofbounds
	CHECK_THROWS(board.move(1, pair(0,1), Board::MoveDIR::Down));//move on another player
	   CHECK_THROWS(board.move(1, pair(0,0), Board::MoveDIR::Up));//move a non existing soldier
	CHECK_THROWS(board.move(2, pair(0,1), Board::MoveDIR::Up));//soldier doesnt belong to the input player
}

TEST_CASE("testing legal moves"){
	Board board(3,3);
	board[pair(0,0)] = new FootCommander(1);
	board[pair(2,2)] = new FootSoldier(2);
	board.move(1,pair(0,0),Board::MoveDIR::Down);
	board.move(2,pair(2,2),Board::MoveDIR::Up);
	CHECK(board[pair(1,2)]->getHealth()==80);
	CHECK(board[pair(1,0)]->getHealth()==140);
	board.move(1,pair(1,0),Board::MoveDIR::Right);
	board.move(2,pair(1,2),Board::MoveDIR::Down);
	CHECK(board[pair(2,2)]->getHealth()==60);
	CHECK(board[pair(1,1)]->getHealth()==130);
	board.move(1,pair(1,1),Board::MoveDIR::Up);
	board.move(2,pair(2,2),Board::MoveDIR::Left);
	CHECK(board[pair(2,1)]->getHealth()==40);
	CHECK(board[pair(0,1)]->getHealth()==120);
	board.move(1,pair(0,1),Board::MoveDIR::Left);
	board.move(2,pair(2,1),Board::MoveDIR::Right);
	CHECK(board[pair(2,2)]->getHealth()==20);
	CHECK(board[pair(0,0)]->getHealth()==110);
	board.move(1,pair(0,0),Board::MoveDIR::Down);
	CHECK(board.has_soldiers(1));
	CHECK(!board.has_soldiers(2));
}

TEST_CASE("testing Commander"){
	Board board(3,3);
	board[pair(0,0)] = new FootCommander(1);
	board[pair(1,0)] = new FootSoldier(1);
	board[pair(2,2)] = new FootSoldier(2);
	board.move(1,pair(0,0),Board::MoveDIR::Right);
	CHECK(board[pair(2,2)]->getHealth()==70);//both commander and his soldier shot
	board.move(1,pair(1,0),Board::MoveDIR::Right);
	CHECK(board[pair(2,2)]->getHealth()==60);//test that a soldier doesnt influence his commander
}
TEST_CASE("aprar"){
	Soldier* s=new FootCommander(1);
	s->damage(10);
	CHECK(s->getHealth()==140);
}

TEST_CASE("testing tests"){
	Board board(3,3);
	board[pair(0,0)] = new FootSoldier(1);
	for(int i=0;i<100;i++){
	CHECK(board[pair(0,0)]->getHealth()==100);		
	}
}
