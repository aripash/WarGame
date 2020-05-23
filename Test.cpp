#include "doctest.h"
#include "DemoGame.hpp"  
#include <iostream>
#include <string>


using namespace WarGame;
TEST_CASE("testing tests"){
	DemoGame demoGame;
	for(int i=0;i<100;i++){
	CHECK(demoGame.play()==0);		
	}
}
