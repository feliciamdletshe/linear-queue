#include<iostream>
#include<string>
using namespace std;

int i = 0;
//structure process
struct Process{
	int number;
	int ttl;
};

//function to perform time decrement operation
int decrementTime(Process q){
	int time = q.ttl;
	time--;
	return time;
}
//function to enqueue process at end of array (Queue)
Process* enqueueBack(Process q[]){
	Process temp = q[0];
	q[0] = q[i - 1];
	q[i - 1] = temp;
	return q;
}
//function to perform dequeue operation
void dequeue(Process q[]){
	for (int j = 0; j < i-1; j++){
		q[j] = q[j + 1];
	}
	i--;

}
int main(){
	
	int no_pro;
	int number;
	cout << "Enter Number of Process: ";
	cin >> no_pro;
	//Queue Of Processes
	Process *q = new Process[no_pro];
	for (i = 0; i < no_pro; i++){
		cout << "\nEnter Process Number (in range 1000 to 2000): ";
		cin >> q[i].number;
		if (q[i].number == 0)
			break;
		cout << "\nEnter process "<<q[i].number<<" time (in range 1 to 25):";
		cin >> q[i].ttl;
	}
	int count = 0;
	while (count<i){
		if (q[count].ttl>0){
			q[count].ttl = decrementTime(q[count]);
			if (q[count].ttl > 0){
				cout << "\nEnQueue Process " << q[0].number << " at back";
				q = enqueueBack(q);
			}
			else
			{
				cout << "\nCompleted Process  Number: " << q[0].number;
				dequeue(q);
			}
		}
	}
	cout << "\nAll Process Completed!!" << endl;
}