class Soldier{
	protected:
	int _maxHealth;
	int _health;
	int _damage;
	uint _owner;
	
	public:
	Soldier(uint owner):_owner{owner}{}
	virtual void action(){}

	Soldier* damage(int damage){
		_health-=damage;
		if(_health<=0)return nullptr;
		if(_health>_maxHealth){
			_health=_maxHealth;
			return this;
		}
		return this;
	}
	uint getOwner(){return _owner;}
	int getHealth(){return _health;}
	

};