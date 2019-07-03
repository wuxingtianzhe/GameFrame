#include "stdin_channel.h"

using namespace std;

stdin_channel::stdin_channel()
{
}

string stdin_channel::readfd()
{
	string ret;
	
	cin >> ret;

	return ret;
}




stdin_channel::~stdin_channel()
{
}
