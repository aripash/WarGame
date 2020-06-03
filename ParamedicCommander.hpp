#include <vector>

using namespace std;

class ParamedicCommander : public Paramedic{
	
	public:
	ParamedicCommander(uint owner):Paramedic{owner}{_maxHealth=200; _health=200; _damage=-999;}
	
	virtual void action(vector<vector<Soldier*>> &board, pair<int,int> me){
		if(board.empty()){

				int y=me.first;
				int x=me.second;
			
				bool found=false;
				for(int i=-1;i<=1||found;i++){
					for(int j=-1;j<=1||found;j++){
						Soldier* temp=board.at(i+y).at(j+x);
						if(temp!=nullptr){
							if(temp->getOwner()==_owner){
								temp->damage(_damage);
								found=true;
							}
						}
					}
				}
				
				for(int i =0;i<board.size();i++){
					for(int j=0;j<board.at(0).size();j++){
						Soldier* temp=board.at(i).at(j);
						if(typeid(temp)==typeid(Paramedic))temp->action(board, pair(i,j));
					}
				}
			
		}
		
	}

}; 