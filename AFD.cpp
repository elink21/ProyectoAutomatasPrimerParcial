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
				//Movimiento entre posiciones;
				position=graph[position].transitions[word[i]];
				cout<<"\n El automata se movio estado "<<position<<" ,con la letra: "<<word[i];
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
	node state1,state2;
	vector<node>test;

	Automaton testAut;

	state1.startState=true;
	state1.endState=true;
	state1.transitions['b']=0;
	state1.transitions['a']=1;

	state2.startState=false;
	state2.endState=false;
	state2.transitions['b']=1;
	state2.transitions['a']=0;
	test.push_back(state1);
	test.push_back(state2);

	testAut.setGraph(test);
	testAut.setAlphabet("ab");

	while(true)
	{
		string t;
		cout<<"\n\nIngrese palabra: ";
		cin>>t;
		if(testAut.isAcceptedWord(t))
		{
			cout<<"\n\nPalabra aceptada!";
		}
		else cout<<"\n\nPalabra rechazada ):";
	}
}