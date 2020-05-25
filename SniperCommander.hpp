
class SniperCommander : public Sniper{
	
	public:
	SniperCommander(uint owner):Sniper{owner}{_maxHealth=120; _health=120; _damage=100;}
	virtual void action(){}

}; 