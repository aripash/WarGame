
class FootCommander : public FootSoldier{
	
	public:
	FootCommander(uint owner):FootSoldier{owner}{_maxHealth=150; _health=150; _damage=20;}
	virtual void action(){}

};