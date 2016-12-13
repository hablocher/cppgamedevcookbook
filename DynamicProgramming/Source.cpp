#include <iostream>
#include <conio.h>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int TotalWeight, int individual_weight[], int individual_value[], int size)
{
	if (size == 0 || TotalWeight == 0)
		return 0;
	if (individual_weight[size - 1] > TotalWeight)
		return knapSack(TotalWeight, individual_weight, individual_value, size - 1);
	else return max(individual_value[size - 1] +
		knapSack(TotalWeight - individual_weight[size - 1], individual_weight, individual_value, size - 1),
		knapSack(TotalWeight, individual_weight, individual_value, size - 1)
	);
}

int main()
{
	int individual_value[] = { 60,100,120 };
	int individual_weight[] = { 10,25,40 };
	int TotalWeight = 60;
	int size = sizeof(individual_value) / sizeof(individual_weight[0]);
	cout << "Total value of sack " << knapSack(TotalWeight, individual_weight, individual_value, size);
	_getch();
	return 0;
}
