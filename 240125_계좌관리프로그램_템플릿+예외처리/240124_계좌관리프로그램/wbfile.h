#pragma once

class wbfile
{
private:
	static string file_name;

public:
	// text mode
	static void save(wbarray<Account *> *parr);
	static int load(wbarray<Account*> *parr);
};