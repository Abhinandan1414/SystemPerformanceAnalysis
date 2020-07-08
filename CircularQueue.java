/*
       Completely re-written by Dr. Abhinandan H. Patil as multiple incorrect versions are floating on net.	
	
*/

class CircularQueue {
  	private
		int max,rear,front,numOfElem;
		int[] a;
	
  	public
		CircularQueue(int m) {
		  max = m;
		  a = new int[m];
		  rear = front = 0;
		  numOfElem = 0;
		}
	
	void insert(int val) {
				if(rear < max)
				{
				     a[rear] = val;
				     rear++;
				     System.out.println("front: "+front+"rear: "+rear);
				}
				else
				{
					rear=rear-max;
				        a[rear] = val;
					rear++;
				        System.out.println("front: "+front+"rear: "+rear);
				}
				if( numOfElem < max)
				numOfElem++;
	  }

	void display() {
		int i;
		for(i=front; i<numOfElem; i++) {
			System.out.print(a[i] + " ");
		}
		//System.out.print(a[i] + " ");
		System.out.println();
	}

	//------------------------

	int delete() {
		if( front == 0 && rear == 0) {
			System.out.println("Underflow");
			return -1;
		} else {
			        int temp = a[front];
				front+=1;
				if (front >= max)
				{
					front=front-max;
					rear = front;
					numOfElem = 0;
				}
				//numOfElem-=1;
			        return temp;
   			}
		}
	public static void main(String[] agrs) {
		CircularQueue q = new CircularQueue(5);
		q.insert(10);
		q.insert(20);
		q.insert(30);
		q.insert(40);
		q.display();
		q.insert(50);
		q.display();
		q.insert(60);
		q.insert(70);
		q.display();
		q.delete(); 
		q.display();

		q.delete(); 
		q.display();

		q.delete(); 
		q.display();

		q.delete(); 
		q.delete();
		q.display();

		q.insert(60);
		q.insert(70);
		q.insert(80);
		q.display();
		q.delete();
		q.display();

	}
}
