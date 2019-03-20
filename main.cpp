
#include <random>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
using namespace std;
struct Team
{
	double ranking;
	int number;
	int cargo;
	int hatch;
	int def;
};
const int TEAMS = 40;
const double MATCHES_PER_TEAM = 12;

bool compare(const Team &a, const Team &b)
{
    return a.ranking/MATCHES_PER_TEAM < b.ranking/MATCHES_PER_TEAM;
}

int main()
{
	srand (time(NULL));
	vector<Team> teams;
	for(unsigned int i=0; i < TEAMS; i++)
	{
		teams.push_back({0,rand()%8000,0,0});
	}
	teams[0].number = 3604;
	for(unsigned int i=0; i < TEAMS; i++)
	{
		for(unsigned int j = 0; j <MATCHES_PER_TEAM; j++)
		{
			double cargoSuccess = 0.5+((rand()%50)/100.0);
			double hatchSuccess = 0.5+((rand()%50)/100.0);
			bool defensePlayed = (rand()%100 < 85) ? 0 : 1;
			bool defensePlayedOn = (rand()%100 < 85) ? 0 : 1;
			double cargo = rand()%4;
			teams[i].cargo += cargo;
			double hatch = rand()%4;
			teams[i].hatch += hatch;
			double climb = rand()%3;
			double climbed = rand()%2;

			teams[i].def += defensePlayed;
			const double A = 2;
			const double B = 3;
			const double C = 4;
			const double D = 1;

			teams[i].ranking += (((cargo * cargoSuccess)*(defensePlayedOn ? 1.5 : 1 ))*A) +
					((hatch*hatchSuccess) * (defensePlayedOn ? 1.5 : 1) * B) +
					(defensePlayed * 2 * C) +
					(climb * climbed * D);
		}
	}
	sort(teams.begin(),teams.end(),compare);

	for(unsigned int i = 0; i < TEAMS; i++)
	{
		cout << "TEAM " << teams[i].number << ": " << teams[i].ranking/MATCHES_PER_TEAM << " :: " << teams[i].cargo << " : " << teams[i].hatch << " : " << teams[i].def << endl;
	}
	return 0;
}
