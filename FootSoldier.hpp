#include <vector>
#include <cmath>

using namespace std;

class FootSoldier : public Soldier{
	
	public:
	FootSoldier(uint owner):Soldier{owner}{_maxHealth=100; _health=100; _damage=10;}
	virtual void action(vector<vector<Soldier*>> &board, pair<int,int> me){
		if(board.empty()){
				int y=me.first;
				int x=me.second;
				double mindistance=9999;
				Soldier* closest=nullptr;
				
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
						}
					}
				}
				
				
				if(closest!=nullptr){
					if((closest->damage(_damage))==0)closest=nullptr;
				}
		}
	}

};