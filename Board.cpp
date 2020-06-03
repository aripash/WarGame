
#include "Board.hpp"

using namespace WarGame;

Soldier*& Board:: operator[](std::pair<int,int> location){
		return board.at(location.first).at(location.second);
	}
Soldier* Board:: operator[](std::pair<int,int> location) const{
		return board.at(location.first).at(location.second);
	}
void Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
	
		if((*this)[source]==nullptr)throw "std::invalid_argument(noone)";
		if((*this)[source]->getOwner()!=player_number)throw "std::invalid_argument(mine)";
		
		int x=0;
		int y=0;
		if(direction==MoveDIR::Up)y=-1;
		else if(direction==MoveDIR::Down)y=1;
		else if(direction==MoveDIR::Left)x=-1;
		else if(direction==MoveDIR::Right)x=1;
		std::pair destination(source.first+y,source.second+x);
		
		if(destination.first<0||destination.first>=board.size())throw "std::invalid_argument(ooby)";
		if(destination.second<0||destination.second>=board.at(0).size())throw "std::invalid_argument(oobx)";
		if((*this)[destination]!=nullptr)throw "std::invalid_argument(who)";
		
		(*this)[destination]=(*this)[source];
		(*this)[source]=nullptr;
		(*this)[destination]->action(board, destination);
		
		
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