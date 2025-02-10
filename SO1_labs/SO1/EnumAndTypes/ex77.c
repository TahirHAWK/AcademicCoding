/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void addGameResult(struct teamSeason *team, enum gameResult result);
int getScore(struct teamSeason team);

enum gameResult {
	DEFEAT,
	DRAW, 
	WIN
};

struct teamSeason {
	int victories, draws, losses;
};

int main() {
	struct teamSeason team1 = {0};
	printf("		 win		drw	def | points\n");
	addGameResult(&team1, WIN);
	printf("Win		: %d		%d	%d   | %d\n", team1.victories, team1.draws, team1.losses, getScore(team1));
	addGameResult(&team1, DEFEAT);
	printf("Defeat		: %d		%d	%d   | %d\n", team1.victories, team1.draws, team1.losses, getScore(team1));
	addGameResult(&team1, WIN);
	printf("Win		: %d		%d	%d   | %d\n", team1.victories, team1.draws, team1.losses, getScore(team1));
	addGameResult(&team1, DRAW);
	printf("Draw		: %d		%d	%d   | %d\n", team1.victories, team1.draws, team1.losses, getScore(team1));
	addGameResult(&team1, WIN);
	printf("Win		: %d		%d	%d   | %d\n", team1.victories, team1.draws, team1.losses, getScore(team1));

	return 0;
}
void addGameResult(struct teamSeason *team, enum gameResult result) {
	switch (result) {
	case DEFEAT:
		team->losses++;
		break;
	case DRAW:
		team->draws++;
		break;
	case WIN:
		team->victories++;
		break;
	default:
		break;
	}
}


int getScore(struct teamSeason team) {
	return (team.victories * 3) + (team.draws * 1) + (team.losses*0);
}
*/
#include<stdio.h>
int main() {
	int x, y;
	int z = scanf("%d,%d", &x, &y);
	printf("%d ", z);
	return 0;
}