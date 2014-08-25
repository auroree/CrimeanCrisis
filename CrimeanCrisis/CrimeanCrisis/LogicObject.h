#pragma once

class LogicObject
{
public:
	LogicObject();
	virtual ~LogicObject();

private:
	int id;
	int x, y;		// po³o¿enie na mapie
	int dx, dy;		// po³o¿enie docelowe (jeœli jednostka w ruchu, jeœli stoi to dx == x, dy == y)
};

