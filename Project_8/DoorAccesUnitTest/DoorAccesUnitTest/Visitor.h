#pragma once
class Visitor
{
private:
	char VisitorPin[6];

public:
	Visitor();
	~Visitor();
	void GetPIN(char RandPin[6]);
};

