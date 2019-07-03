#pragma once
#include<iostream>
using namespace std;
class stdin_channel
{
public:
	stdin_channel();
	string readfd();
	virtual ~stdin_channel();
};

