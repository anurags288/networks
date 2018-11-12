#include<iostream>
using namespace std;

int main()
{
	
	int totalV, targetV, adjV;
	
	
	cout<<"Enter the total number of routers in the network: ";
	cin>>totalV;
	cout<<"\nEnter the Vertex Whose routing table is to be Found: ";
	cin>>targetV;
	cout<<"\nEnter the number of routers adjacent to Target Vertex "<<targetV<<": ";
	cin>>adjV;
	
	int delay[adjV];
	
	int TargetDVT[totalV];
	int OutLine[totalV];
	
	int NeighbourDVT[totalV][adjV];
	
	int NeighbourNum[adjV];
	
	 for(int j = 0; j < adjV; ++j) {
	 	
	 	cout<<"\nEnter the number of "<<j+1<<"th adjacent router : ";
		cin>>NeighbourNum[j];
	 	
	 	
	 	cout<<"\nFill the routing table for router number "<<NeighbourNum[j]<<":\n";
	 	for(int i = 0; i < totalV; ++i) {

			cout<<"\n"<<i+1<<".  ";

	 		
	 		/*if(i+1 == NeighbourNum[i]) {
	 			NeighbourDVT[i][j] = 0;
	 			cout<<NeighbourDVT[i][j];
			 }*/
			 
			 //else {
			 	cin>>NeighbourDVT[i][j];
			 //}
		 }
		 
		 
		cout<<"\nEnter the Delay from Target router "<<targetV<<" to Adjacent Vertex "<<NeighbourNum[j]<<": ";
		cin>>delay[j];	 
		
	}
	
	int i, j, min, Outgoingline;
	
	for(i = 0; i < totalV; ++i) {
		
		min = 100000;
		
		if(i+1 != targetV) {
			
		
		
			 for(j = 0; j < adjV; ++j) {
		 		
		 			if(min > NeighbourDVT[i][j] + delay[j]) {
		 				min = NeighbourDVT[i][j] + delay[j];
		 				Outgoingline = NeighbourNum[j];
					 }
			}
		
		
			TargetDVT[i] = min;
			OutLine[i] = Outgoingline;
		}
		
		else {
			
			TargetDVT[i] = 0;
			OutLine[i] = 0;
		}
		
	}
	
		cout<<"\n\nRecieved Vector Tables: \n";
		for(j = 0; j < adjV; ++j) {
		 	
		 	cout<<"   "<<NeighbourNum[j]<<"\t";
		 }	
		 
		 cout<<"\n\n";
		 
	for(i = 0; i < totalV; ++i) {
		
		cout<<i+1<<". ";
				
		 for(j = 0; j < adjV; ++j) {
		 	
		 	cout<<NeighbourDVT[i][j]<<"\t";
		 }
cout<<endl;	
}
	
	
	cout<<"\n\nRouting table for "<<targetV<<" is :"<<endl;
	for(int i = 0; i < totalV; i++) {
				
			cout<<"\n"<<TargetDVT[i]<<"\t"<<OutLine[i];		
	}
	
	
	return 0;
	
}
	
	

