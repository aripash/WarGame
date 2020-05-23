
class FootSoldier : public Soldier{
	
	public:
	FootSoldier(uint owner):Soldier{owner}{_maxHealth=100; _health=100; _damage=10;}
	virtual void action(){}

};