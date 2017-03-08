#include <bits/stdc++.h>
using namespace std;


class node{

public:
	int stateNumber;
	map<char,int> transitions;
	bool endState;
	bool startState;
};

class Automaton{
protected:


private:
	vector<node> graph;
	vector<char> alphabet;
public:
	int evaluateLetter(char letter)
	{
		//Revisara la letra y regresara un estado para seguir evaluando

		return 0;
	}

	bool isInAlphabet(char letter)
	{
		//Verificara que la palabra este en el alfabeto
		return false;
	}

	void setGraph(vector<node> g)
	{
		//metodo que copiara el grafo de entrada a esta clase Automata
	}

	void setAlphabet(vector<char> a)
	{
		//metodo que copiara el alfabeto de entrada
	}



};

int main()
{

}