#include <iostream>
#include <fstream>

int CalculateFuel(int mass)
{
	return ((mass / 3) - 2);
}

int CalculateTotalFuel(int mass)
{
	int fuel = CalculateFuel(mass);
	int sum = 0;

	while (fuel > 0)
	{
		sum += fuel;
		fuel = CalculateFuel(fuel);
	}

	return sum;
}

int main()
{
	std::ifstream datafile("day1-data.txt", std::ios_base::in);
	int data;

	int sumOfFuel = 0, totalSumOfFuel = 0;

	while (datafile >> data)
	{
		sumOfFuel += CalculateFuel(data);
		totalSumOfFuel += CalculateTotalFuel(data);
	}

	// Part 1:
	std::cout << "Fuel requirements: " << sumOfFuel << std::endl;
	// Part 2:
	std::cout << "Total fuel requirements: " << totalSumOfFuel << std::endl;
}

