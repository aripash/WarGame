
class ParamedicCommander : public Soldier{
	
	public:
	ParamedicCommander(uint owner):Soldier{owner}{_maxHealth=200; _health=200; _damage=-999;}
	virtual void action(){}

}; 