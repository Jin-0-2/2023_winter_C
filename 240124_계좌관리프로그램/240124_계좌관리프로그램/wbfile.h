#pragma once

class wbfile
{
private:
	static string file_name;

public:
	// text mode
	static void save(wbarray* parr);
	static int load(wbarray* parr);
};