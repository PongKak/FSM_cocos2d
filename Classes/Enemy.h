#pragma once

#include "EnemyState.h"



class Enemy : public Sprite
{
public :
	CREATE_FUNC(Enemy);

	virtual bool      init();
	virtual void      update(float dt) override;

	/* State */
	template<typename T_STATE>
	void              changeState();

	EnemyState*       getState();
	void              setState(EnemyState*);

	/* Functions */
	Vec2			  getPosition();
	void			  setInteval(Vec2);
	float			  getDistance();
	Vec2              getUnitVec();
	void              move(Vec2, float);
	float             getOriginDistance();
	Vec2              getOrigin();
	Vec2			  getOriginUnitVec();


private :
	Sprite*           m_pHead;
	EnemyState*		  m_pState;

	Vec2	          m_Origin;
	Vec2			  m_Interval;
	float			  m_Distance;

};


// State�� ��ȯ.
template <typename T_STATE>
void Enemy::changeState()
{
	// state�� �����Ѵٸ� ����.
	if (m_pState)
	{
		getState()->endState(this);
		removeComponent(m_pState);
	}

	auto m_pState = T_STATE::create();
	setState(m_pState);
	getState()->startState(this);
	addComponent(m_pState);

	return;
}