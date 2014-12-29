#pragma once

#include "Starfield.h"
#include <string>
#include "TextureManager.h"
#include "Game.h"

class StarfieldSequence
{
public:
	StarfieldSequence(Camera* camera, int seed)
		: mSeed(seed)
		, pCamera(camera)
	{
		TheTextureManager::Instance()->load("Assets/Star.png", "Star", TheGame::Instance()->getRenderer());

		//A constructor which accepts a seed, and splits it into two
		std::string s_seedTemp;
		mStarfield = new Starfield(camera); //Initialize the Starfield
		std::string  s_seed = std::to_string(seed); //Store the seed in a string so that we can easily split it

		//Add zeros to the string if the seed doesn't have four digits
		if (seed < 10){
			s_seedTemp = "000";
			s_seedTemp = s_seedTemp.append(std::to_string(seed));
		}
		else if (seed < 100){
			s_seedTemp = "00";
			s_seedTemp = s_seedTemp.append(std::to_string(seed));
		}
		else if (seed < 1000){
			s_seedTemp = "0";
			s_seedTemp = s_seedTemp.append(std::to_string(seed));
		}
		else {
			s_seedTemp = std::to_string(seed);
		}

		//Split the seed into two - the first two digits are stored in s_start, while the last two are stored in s_end
		s_start = std::stoi(s_seedTemp.substr(0, 2));
		s_end = std::stoi(s_seedTemp.substr(2, 4));

		std::cout << "Seed: " << s_seedTemp << std::endl;
	}

	int getNext()
	{
		//A method that returns the next number in the sequence
		return (s_start + s_end);
	}

	void fixDigits(){
		std::string temp = "";
		//If the newly-generated number has more than three digits, only take the last three
		if (s_current > 999){
			temp = std::to_string(s_current);
			s_current = std::stoi(temp.substr(1, 4));
		}
		//If the newly-generated number has less than three digits, add zeros to the beginning
		if (s_current < 10){
			s_sequence += "00";
		}
		else if (s_current < 100){
			s_sequence += "0";
		}
	}

	Star * getStar(int i){
		//A method which accepts an integer (the size of the sequence) and returns the Star

		//Split the last nine digits in the sequence into three (the three attributes of the star)
		Star * star = new Star(pCamera, new LoaderParams(
			std::stoi(s_sequence.substr(i - 9, i - 6)),//X
			std::stoi(s_sequence.substr(i - 6, i - 3)),//Y
			20,//With
			20,//Height
			"Star"),
			std::stoi(s_sequence.substr(i - 3, i))); //Size

		return star;
	}

	void generate(int starnumber)
	{
		//Generates a number of stars as indicated by the integer starnumber
		int s_counter = 9 * starnumber; //s_counter keeps track of the number of characters the String must have to generate the designated number of stars
		s_counter -= 1; //Remove one since a String starts from index 0
		int s_starcounter = 0; //s_starcounter keeps track of the number of numbers generated

		for (int i = 1; s_sequence.length() <= s_counter; i++)
		{
			s_current = getNext(); //Generate the next number in the sequence
			fixDigits(); //Make sure the number has three digits
			s_sequence += s_current; //Add the new number to the sequence
			s_starcounter++;

			if (s_starcounter >= 3 && s_starcounter % 3 == 0){
				//If three numbers have been generated since the last star was created, create another one
				mStarfield->AddStar(getStar(s_sequence.length()));
			}

			//Replace s_start and s_end, or else you will keep on generating the same number over and over again!
			s_start = s_end;
			s_end = s_current;

		}
	}

	void update(Uint32 dTime)
	{

	}

	void draw()
	{
		mStarfield->draw();
	}

private:
	int mSeed;
	Camera * pCamera;
	Starfield * mStarfield;

	std::string s_seed, s_sequence;
	int s_start, s_end, s_current;
};