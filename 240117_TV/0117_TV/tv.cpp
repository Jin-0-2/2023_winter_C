// tv.cpp
#include <iostream>
using namespace std;
#include "tv.h"

tv::tv()
{
	power = false;
	channel = 2;
	volume = 5;
}

tv::tv(int _channel, int _volume)
{
	power = false;
	channel = _channel;
	volume = _volume;
}

bool tv::get_onoff()
{
	return power;
}

int tv::get_channel()
{
	return channel;
}

int tv::get_volume()
{
	return volume;
}

void tv::print()
{
	cout << "--------------------------" << endl;
	cout << "전원 : " << ((power == true) ? "ON" : "OFF") << endl;
	cout << "채널 : " << channel << endl;
	cout << "볼륨 : " << volume << endl;
	cout << "--------------------------" << endl;
}

void tv::onoff()
{
	if (power == false)
	{
		power = true;
	}
	else
	{
		power = false;
	}
}
void tv::channel_up()
{
	if (get_onoff() == false)
	{
		cout << "전원이 OFF입니다. 전원을 ON해주십시오." << endl;
		return;
	}
	else
	{
		if (channel == 50)
		{
			channel = 0;
			cout << "채널을 위로 한칸 이동합니다." << endl;
		}
		else
		{
			channel = channel + 1;
			cout << "채널을 위로 한칸 이동합니다." << endl;
		}
	}
}
void tv::channel_down()
{
	if (get_onoff() == false)
	{
		cout << "전원이 OFF입니다. 전원을 ON해주십시오." << endl;
		return;
	}
	else
	{
		if (channel == 0)
		{
			channel = 50;
			cout << "채널을 아래로 한칸 이동합니다." << endl;
		}
		else
		{
			channel = channel - 1;
			cout << "채널을 아래로 한칸 이동합니다." << endl;
		}
	}
}
bool tv::channel_input(int _channel)
{
	if (_channel > 50 || _channel < 0)
	{
		return false;
	}
	else
	{
		channel = _channel;
		return true;
	}
}
void tv::volume_up()
{
	if (get_onoff() == false)
	{
		cout << "전원이 OFF입니다. 전원을 ON해주십시오." << endl;
		return;
	}
	else
	{
		if (volume >= 30)
			{
				cout << "최대 볼륨입니다!!!" << endl;
				return;
			}
		else
		{
			cout << "볼륨을 1 증가합니다." << endl;
			volume = volume + 1;
		}
			
	}
}
void tv::volume_down()
{
	if (get_onoff() == false)
	{
		cout << "전원이 OFF입니다. 전원을 ON해주십시오." << endl;
		return;
	}
	else
	{
		if (volume <= 0)
		{
			cout << "최소 볼륨입니다!!!" << endl;
			return;
		}
		else
		{
			cout << "볼륨을 1 감소합니다." << endl;
			volume = volume - 1;
		}
	}
}