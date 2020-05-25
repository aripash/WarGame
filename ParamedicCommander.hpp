
class ParamedicCommander : public Paramedic{
	
	public:
	ParamedicCommander(uint owner):Paramedic{owner}{_maxHealth=200; _health=200; _damage=-999;}
	virtual void action(){}

}; 