#pragma once
class tv
{
private:
	bool power;
	int channel;		// 유효범위 : 0 ~ 50
	int volume;

public:
	tv();
	tv(int _channel, int _volume);

public:
	bool get_onoff();
	int get_channel();
	int get_volume();
	void print();

	void onoff();
	void channel_up();
	void channel_down();
	bool channel_input(int _channel);
	void volume_up();
	void volume_down();
};