#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Search.h"
#include "EnemyState_Return.h"

const float RETURN_RANGE = 500.f;

void EnemyState_Approach::startState(Enemy* enemy)
{
	CCLOG("start_Approach!");
}

// ���� �ڸ����� 500 �ȼ� �ȱ����� �߰��Ѵ�.
// 500�ȼ��� �Ѿ�� �ٽ� ���ڸ��� ���ư����� state�� ����.
void EnemyState_Approach::runState(Enemy* enemy, float dt)
{
	float originDistance = enemy->getOriginDistance();
	
	if (originDistance < RETURN_RANGE)
	{
		auto unitVec = enemy->getUnitVec();
		enemy->move(unitVec, dt);
	}
	else
	{
		enemy->changeState<EnemyState_Return>();
	}

}

void EnemyState_Approach::endState(Enemy* enemy)
{
	CCLOG("end_Approach!");
}