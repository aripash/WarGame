
class Paramedic : public Soldier{
	
	public:
	Paramedic(uint owner):Soldier{owner}{_maxHealth=100; _health=100; _damage=-999;}
	virtual void action(){}

}; 