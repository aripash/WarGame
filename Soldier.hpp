#include <vector>

using namespace std;

class Soldier{
	protected:
	int _maxHealth;
	int _health;
	int _damage;
	uint _owner;
	
	public:
	Soldier(uint owner):_owner{owner}{}
	
	virtual void action(vector<vector<Soldier*>> &board, pair<int,int> me){}

	int damage(int damage){
		_health-=damage;
		if(_health<0) _health=0;
		else if(_health>_maxHealth) _health=_maxHealth;
		return _health;
	}
	uint getOwner(){return _owner;}
	int getHealth(){return _health;}
	

};