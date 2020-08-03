/*
	Game Engine Object

	This file is part of the BPM Game Engine.

	Copyright (C) 2020 Fabio Takeshi Ishikawa
*/

#ifndef GAME_ENGINE_OBJECT_H
#define GAME_ENGINE_OBJECT_H

class GEObject
{
public:
	virtual void update() {}
	virtual void draw() {}
};

#endif