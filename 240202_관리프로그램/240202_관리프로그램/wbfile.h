#pragma once
class wbfile
{
private:
	static string file_name;

public:
	// text mode
	static void save(const vector<Member*>& parr); // �� ����
	static int load(vector<Member*>* parr);
};