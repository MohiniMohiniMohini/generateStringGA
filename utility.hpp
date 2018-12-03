#include <string>
using namespace std;

const string GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP"\
"QRSTUVWXYZ 1234567890, '.-;:_!\"#%&/()=?@${[]}";

string TARGET;

// Function to generate random numbers in given range
int random_num(int start, int end)
{
	int range = (end-start)+1;
	int random_int = start+(rand()%range);
	return random_int;
}

// Function to generate float random numbers between 0&1
float random_probability()
{
    float random = ((float) rand()) / (float) RAND_MAX;
	return random;
}

// Create random genes for mutation
char mutated_genes()
{
	int len = GENES.size();
	int r = random_num(0, len-1);
	return GENES[r];
}

// create chromosome or string of genes
string create_gnome(int len)
{
	string gnome = "";
	for(int i = 0;i<len;i++)
		gnome += mutated_genes();
	return gnome;
}


