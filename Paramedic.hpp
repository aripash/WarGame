#include <vector>

using namespace std;

class Paramedic : public Soldier{
	
	public:
	Paramedic(uint owner):Soldier{owner}{_maxHealth=100; _health=100; _damage=-999;}
	
	virtual void action(vector<vector<Soldier*>> &board, pair<int,int> me){
		if(board.empty()){

				int y=me.first;
				int x=me.second;
			
				bool found=false;
				for(int i=-1;i<=1||found;i++){
					for(int j=-1;j<=1||found;j++){
						soldier* temp=board.at(i+y).at(j+x);
						if(temp!=nullptr){
							if(temp.getOwner()==_owner){
								temp->damage(_damage);
								found=true;
							}
						}
					}
				}
			
		}
	}

}; 