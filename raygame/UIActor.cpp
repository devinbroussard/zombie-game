#include "UIActor.h"
#include "Transform2D.h"

UIActor::UIActor(int x ,int y, int fontSize, const char* text)
{
	m_fontSize = fontSize;
	m_text = text;
	m_x = x;
	m_y = y;
}

void UIActor::draw()
{
	Rectangle rec = Rectangle();
	DrawText(m_text, m_x, m_y , m_fontSize, BLACK);
}
