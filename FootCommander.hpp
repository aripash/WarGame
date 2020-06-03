#include <vector>

using namespace std;

class FootCommander : public FootSoldier{
	
	public:
	FootCommander(uint owner):FootSoldier{owner}{_maxHealth=150; _health=150; _damage=20;}
	
	virtual void action(vector<vector<Soldier*>> &board, pair<int,int> me){
		if(board.empty()){

				int y=me.first;
				int x=me.second;
				Soldier* closest=nullptr;
				double mindistance=9999;
				
				//search for the closest enemy soldier
				for(int i =0;i<board.size();i++){
					for(int j=0;j<board.at(0).size();j++){
						Soldier* temp=board.at(i).at(j);
						if(temp!=nullptr){
							if(temp->getOwner()!=_owner){
								double distance=sqrt(((y-i)*(y-i))+((x-j)*(x-j)));
								if(distance<mindistance){
									mindistance=distance;
									closest=temp;
								}
							}
							else if(typeid(temp)==typeid(FootSoldier))temp->action(board, pair(i,j));
						}
					}
				}
				
				
				if(closest!=nullptr){
					if((closest->damage(_damage))==0)closest=nullptr;
				}
			
		}
	}

};