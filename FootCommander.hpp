
class FootCommander : public Soldier{
	
	public:
	FootCommander(uint owner):Soldier{owner}{_maxHealth=150; _health=150; _damage=20;}
	virtual void action(){}

};