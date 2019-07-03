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

void stdin_channel::writefd(string _output)
{

}

int stdin_channel::Getfd()
{
	return 0;
}

void stdin_channel::data_process(string _input)
{
	//将数据回显到标准输出--》调用标准输出对象的sendout对象
	m_out->data_sendout(_input);
}
