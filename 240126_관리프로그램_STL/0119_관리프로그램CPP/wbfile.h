#pragma once

class wbfile
{
private:
	static string file_name;

public:
	// text mode
	static void save(const vector<drink*>& parr); // °ª ÀúÀå
	static int load(vector<drink*>* parr);
};