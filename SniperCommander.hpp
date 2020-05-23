
class SniperCommander : public Soldier{
	
	public:
	SniperCommander(uint owner):Soldier{owner}{_maxHealth=120; _health=120; _damage=100;}
	virtual void action(){}

}; 