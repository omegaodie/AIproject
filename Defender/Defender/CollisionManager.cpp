#include "CollisionManager.h"

CollisionManager::CollisionManager(const GameData& gdata) : gd(gdata)
{

}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::getcollision(sf::IntRect& aR, sf::IntRect& bR)
{
	if (aR.intersects(bR)) {
   		return true;
	}
	else {
		return false;
	}
}






bool CollisionManager::TestWallCollision(sf::IntRect r)
{
	//if
	return false;
}
