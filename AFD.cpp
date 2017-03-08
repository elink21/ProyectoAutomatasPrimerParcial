#include <bits/stdc++.h>
using namespace std;

struct node
{
	map<char,int> transitions;
	bool endState;
	bool startState;
};

class Automaton{
protected:


private:
	vector<node> graph;
	vector<char> alphabet;
	int position;

	bool isInAlphabet(char letter)
	{
		for(int  i=0;i<alphabet.size();i++)
		{
			if(letter==alphabet[i])return true;
		}
		return false;
	}
public:
	Automaton();
	~Automaton();

	bool isAcceptedWord(string word)
	{
		for(int i=0;i<graph.size();i++)
		{
			if(graph[i].startState)
			{
				position=i;
				break;
			}
		}

		for(int i=0;i<word.size();i++)
		{
			if(isInAlphabet(word[i]))
			{

				position=graph[position].transitions[word[i]];
			}
			else return false;	
		}
		
		if(graph[position].endState)return true;
		return false;
	}

	

	void setGraph(vector<node> g)
	{
		//metodo que copiara el grafo de entrada a esta clase Automata
		for(int i=0;i<g.size();i++)
		{
			this->graph.push_back(g[i]);
		}
	}

	void setAlphabet(string a)
	{
		for(int i=0;i<a.size();i++)
		{
			this->alphabet.push_back(a[i]);
		}
	}



};


int main()
{


}