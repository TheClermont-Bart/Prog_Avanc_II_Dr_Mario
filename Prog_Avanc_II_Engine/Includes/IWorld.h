#pragma once

class IWorld
{
public:
	virtual ~IWorld() = default;
	virtual void FindEntity(const char* name) = 0;

};