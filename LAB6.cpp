#include <iostream>
#include <iomanip>
#include <string> 
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std; 

struct Cube {
	Cube(int _num, string _color, int _lenght) : num{_num}, color(_color), lenght(_lenght) {}
	int num;
	string color;
	int lenght;
};

vector<Cube> getList(string filePath) {
	vector<Cube> result;
	string line, color, colorCheck;
	cout << "введите цвет на английском языке с маленькой буквы(red, yellow, brown, etc.): ";
	cin >> colorCheck;

	ifstream fin(filePath);
	if (fin.is_open()) {
		int num, lenght;
		string color;
		while (fin >> num >> color >> lenght) {
			if (color == colorCheck) {
				result.push_back(Cube{num, color, lenght});
			}
		}
	}
	fin.close();
	return result;
}

void getMaxCubeInformation(const vector<Cube> cubes, int identifier) {
	for (Cube b : cubes) {
		if (b.lenght == identifier) {
			cout << "кубик с максимальным обьемом: " << b.num << " " << b.color << " " << b.lenght << "\n" << " обьем: "  << pow(b.lenght, 3) << "\n";
		}
	}
}

void getMinCubeInformation(const vector<Cube> cubes, int identifier) {
	for (Cube b : cubes) {
		if (b.lenght == identifier) {
			cout << "кубик с манимальным обьемом: " << b.num << " " << b.color << " " << b.lenght << "\n" << " обьем: " << pow(b.lenght, 3) << "\n";
		}
	}
}



int main() {
	setlocale(LC_ALL, "ru");
	double sumOfVolumes = 0.0;
	string path = "LAB6.txt";
	vector<Cube> cubes = getList(path);
	int maxVol = cubes[0].lenght;
	int minVol = cubes[0].lenght;

	for (Cube b : cubes) {
		cout << b.num << " " << b.color << " " << b.lenght << "\n";
		sumOfVolumes += pow(b.lenght, 3);

		if (b.lenght > maxVol) {
			maxVol = b.lenght;
		}

		if (b.lenght < minVol) {
			minVol = b.lenght;
		}
	}
	cout << "Суммарный обьём: " << sumOfVolumes << "\n";
	getMaxCubeInformation(cubes, maxVol);
	getMinCubeInformation(cubes, minVol);

	return 0;
}