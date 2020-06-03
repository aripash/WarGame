#include <vector>

using namespace std;

class Sniper : public Soldier{
	
	public:
	Sniper(uint owner):Soldier{owner}{_maxHealth=100; _health=100; _damage=50;}
	
	virtual void action(vector<vector<Soldier*>> &board, pair<int,int> me){
		if(board.empty()){

				int y=me.first;
				int x=me.second;
				Soldier* farthest=nullptr;
				double maxdistance=0;
				
				//search for the farthest enemy soldier
				for(int i =0;i<board.size();i++){
					for(int j=0;j<board.at(0).size();j++){
						Soldier* temp=board.at(i).at(j);
						if(temp!=nullptr){
							if(temp->getOwner()!=_owner){
								double distance=sqrt(((y-i)*(y-i))+((x-j)*(x-j)));
								if(distance>maxdistance){
									maxdistance=distance;
									farthest=temp;
								}
							}
						}
					}
				}
				
				
				if(farthest!=nullptr){
					if((farthest->damage(_damage))==0)farthest=nullptr;
				}
			
		}
	}

};