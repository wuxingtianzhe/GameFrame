#pragma once
#include<iostream>
#include"Ichannel.h"
using namespace std;
class stdin_channel:public Ichannel
{
public:
	stdin_channel();
	string readfd();
	virtual ~stdin_channel();

	// 通过 Ichannel 继承
	virtual void writefd(string _output) override;
	virtual int Getfd() override;
	virtual void data_process(string _input) override;
};

