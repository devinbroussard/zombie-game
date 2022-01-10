#include "HealthComponent.h"

HealthComponent::HealthComponent(int maxHealth) :
	Component::Component("Health Component")
{
	m_maxHealth = maxHealth;
	m_currentHealth = maxHealth;
	m_damageCooldown = 5;
	m_timeSinceDamage = 0;
}

HealthComponent::~HealthComponent()
{
}

void HealthComponent::takeDamage()
{
	if (m_timeSinceDamage > m_damageCooldown)
	{
		m_timeSinceDamage = 0;
		m_currentHealth--;
	}
}

void HealthComponent::start()
{
	//sets the curretn health to the max
	m_currentHealth = m_maxHealth;
	//sets the time Since Damage to 10 to not get one shot by enemies
	m_timeSinceDamage = 10;
	Component::start();
}

void HealthComponent::update(float deltaTime)
{
	//adds the deltaTIme to the Time Since Damage
	m_timeSinceDamage += deltaTime;
	Component::update(deltaTime);

	//is the health is lowner than 0
	if (m_currentHealth <= 0)
		getOwner()->end();//end game
}

void HealthComponent::onCollision(Actor* actor)
{
	//if the name of the actor is "Enemy"
	if (actor->getName() == "Enemy")
	{
		//collide and decrement health and ...
		m_currentHealth--;
		//...reset the time since damage
		m_timeSinceDamage = 0;
	}
}
