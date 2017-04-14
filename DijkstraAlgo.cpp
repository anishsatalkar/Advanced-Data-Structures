#include<iostream>
#include<string>

using namespace std;
int size;
int visited[10] = {0,0,0,0,0,0,0,0,0,0};
int distanceArr[10] = {500,500,500,500,500,500,500,500,500,500};

struct node
{
	string city;
	int distance;
	node *next = NULL;
}*List[10];

class Dijkstra
{
	public:
	void createList();
	void displayGraph();
	void addEdges();
	void shortestPaths(node *);
	int getIndexOf(string);
	int allVisited();
	int returnIndex();
	void printVisited();
};



int Dijkstra :: getIndexOf(string city)
{	
	int i = 0;
	for(i = 0 ; city.compare(List[i] -> city) && i < size ; i++);
	return i;
}

void Dijkstra :: createList()
{
	
	string city;
	cout<<"\nEnter the number of cities : ";
	cin>>size;
	
	for(int i = 0 ; i < size ; i++)
	{
		cout<<"\nEnter the name of city : ";
		cin>>city;
		List[i] = new node;
		List[i] -> distance = 0;
		List[i] -> city = city;
	}
}

void Dijkstra :: displayGraph()
{
	
	
	for(int i = 0 ; i < size ; i++)
	{
		node *temp = List[i];
		while(temp != NULL)
		{
			cout<<temp -> city <<"->";
			temp = temp -> next;
		}
		cout<<"NULL";
		cout<<"\n";
	}
}



void Dijkstra :: addEdges()
{
	string city0,city1;
	int distance;
	int i = 0;
	cout<<"\nEnter the name of starting city : ";
	cin>>city0;
	
	while(i<size && city0.compare(List[i] -> city))
	i++;
	if(i==size)
	{
		cout<<"\nSpecified city does not exist in the graph. Returning to main.\n";
		return;
	}
	
	node *temp = List[i];
	
	cout<<"\nEnter the name of second city	: ";
	cin>>city1;
	cout<<"\nEnter the distance between the first city and second city : ";
	cin>>distance;
	
	while(temp->next != NULL)
	temp = temp -> next;
	
	temp -> next = new node;
	temp -> next -> city = city1;
	temp -> next -> distance = distance;
}

int Dijkstra :: allVisited()
{
	for(int i = 0 ; i < size ;i++)
	{
		if(visited[i] == 0)
		return 0;
	}return 1;
}


void Dijkstra :: shortestPaths(node *startVertex)
{	

	int i = 0;

	int listIndex = getIndexOf(startVertex->city);	
	
	//cout<<"\nList index is : "<<listIndex;
	
	distanceArr[listIndex] = 0;
	
	while(!allVisited())
	{
		
		node *trav = List[listIndex] -> next;
		
		while(trav != NULL)
		{
			int cityIndex = getIndexOf(trav -> city);
			if(trav -> distance + distanceArr[listIndex] < distanceArr[cityIndex])
				distanceArr[cityIndex] = trav -> distance + distanceArr[listIndex];
			trav = trav -> next;
			
		}
		
		visited[listIndex] = 1;
		
		listIndex = returnIndex();
		
		//printVisited();
		
		
	}
}

void Dijkstra :: printVisited()
{
	for(int i = 0 ; i < size ; i++)
	{
		cout<<visited[i]<<" ";
	}
}

int Dijkstra :: returnIndex()  //It needs to get the minimum value from the distance array only of the unvisited node
{
	int returnVal;
	int min = 499;
	for(int i = 0 ; i < size ; i++)
	{
		if(!visited[i] && (distanceArr[i] < min))
		{
			min = distanceArr[i];
			returnVal = i;
		}
	}
	return returnVal;
}

int main()
{
	Dijkstra d;
	d.createList();
	d.displayGraph();
	d.addEdges();
	d.addEdges();
	d.addEdges();
	d.displayGraph();
	d.shortestPaths(List[0]);		//Starting node is basically the first node in the list
	
	cout<<"\nThe final array with shortest paths from source is : ";
	for(int i = 0 ; i < size ; i++)		//Prints the final distance Array which contains the shortest paths from source
	{
		cout<<distanceArr[i]<<" ";
	}
	
	
	return 0;
}


