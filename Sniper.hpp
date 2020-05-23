
class Sniper : public Soldier{
	
	public:
	Sniper(uint owner):Soldier{owner}{_maxHealth=100; _health=100; _damage=50;}
	virtual void action(){}

};