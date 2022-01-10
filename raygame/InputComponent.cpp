#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Character.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component")
{}

//get Move Axis allow for movement on the x and y axis with the wasd keys.
MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	if (!((Character*)getOwner())->getIsAttacking())
	{
		//Get the direction of the individual axis
		float xDirection = -RAYLIB_H::IsKeyDown(m_left) + RAYLIB_H::IsKeyDown(m_right);
		float yDirection = RAYLIB_H::IsKeyDown(m_down) - RAYLIB_H::IsKeyDown(m_up);

		//Return a new vector representing the move directiodn
		return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
	}
		
	return MathLibrary::Vector2(0, 0);
}


void InputComponent::update(float deltaTime)
{
	//if the key is = to the meleeswing
	if (IsKeyPressed(m_meleeSwing))
		((Character*)getOwner())->setIsAttacking(true);
}


