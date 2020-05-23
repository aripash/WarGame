
#include "Board.hpp"

using namespace WarGame;

Soldier*& Board:: operator[](std::pair<int,int> location){
		return board.at(location.first).at(location.second);
	}
Soldier* Board:: operator[](std::pair<int,int> location) const{
		return board.at(location.first).at(location.second);
	}
void Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
		
	}
bool Board:: has_soldiers(uint player_number) const{
		for(int i =0;i<board.size();i++){
			for(int j=0;j<board.at(0).size();j++){
				std::pair index(i,j);
				auto current=(*this)[index];
				if(current!=nullptr)
				if(current->getOwner()==player_number)return true;
			}
		}
		return false;
	}