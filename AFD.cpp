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
	node s0,s1,s2,s3,s4,s5,s6;
	vector<node>task3;

	s0.startState=true;
	s0.endState=false;
	s0.transitions['0']=1;
	s0.transitions['1']=3;

	s1.startState=false;
	s1.endState=false;
	s1.transitions['0']=2;
	s1.transitions['1']=5;

	s2.startState=false;
	s2.endState=false;
	s2.transitions['0']=2;
	s2.transitions['1']=2;

	s3.startState=false;
	s3.endState=false;
	s3.transitions['0']=4;
	s3.transitions['1']=3;

	s4.startState=false;
	s4.endState=true;
	s4.transitions['0']=2;
	s4.transitions['1']=5;

	s5.startState=false;
	s5.endState=true;
	s5.transitions['0']=4;
	s5.transitions['1']=5;

	task3.push_back(s0);
	task3.push_back(s1);
	task3.push_back(s2);
	task3.push_back(s3);
	task3.push_back(s4);
	task3.push_back(s5);

	Automaton team3;
	team3.setAlphabet("10");
	team3.setGraph(task3);

	while(true)
	{
		string t;
		cout<<"\n\nIngrese palabra: ";
		cin>>t;
		if(team3.isAcceptedWord(t))
		{
			cout<<"\n\nPalabra aceptada!";
		}
		else cout<<"\n\nPalabra rechazada ):";
	}
}