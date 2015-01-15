#pragma once
/*

~~~~~~~~~~~~~~~~~~TO-DOs~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Bugs:
	- (a) When changing states, the old states are still there, i.e memory leak

Incomplete:
	- Movement
	- Shooting
	- Render states below not using because of bug(a) -> renders the states not removed

Features To Add:
	- Procedural Generation of backgrounds
		- Planets
		- 
	- Weapons
		- Rockets
		- Beam
		- Machine Gun
	- Modular Ship Building -> would need real physics engine...

Complete:
	- Menus
	- Procedural Generation of backgrounds
		- Stars
	- Test Movement

Ideas:

Bugs Fixed:
	- calls to functions not calling derived class function from base class pointer, only calls base class function -> "SDLGameObject::draw" vs "Ship::draw" in player draw function skipped calling ship class draw function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Discription:

Space simulator game
- Procedurally generated stars using simplex noise


*/