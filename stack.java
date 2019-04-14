/*
  some pointer error makes me use java not c++
*/
import java.util.Scanner;

public class stackk<T> {
	
	class node{
		private node next; 
		private node prev;
		private node head; 
		private T data;
		public node(T val){
			this.data = val;
		}

		public T getdata(){
			return this.data;
		}
		public node getnext(){
			return this.next;
		}
		public node getprev(){
			return this.prev;
		}
		public void setdata(T data){
			this.data = data;
		}
		public void setnext(node a){
			this.next = a;
		}
		public void setprev(node a){
			this.prev = a;
		}
		
	}
	int size;
	node head;
	node top;
	stackk(){
		size=0;
	}
	void push(T info) {
		node in=new node(info);
		node tmp;
		if(size==0) {
			top=in;
			size++;
		}else {
			tmp=top;
			top=in;
			top.setprev(tmp);
			size++;
		}
		//System.out.println(in.getdata());
	}
	T top() {
		return top.getdata();
	}
	T pop() {//t type
		T temp=null;
		if(size<0)return temp;
		if(size!=0) {
			temp=top.getdata();
			top=top.getprev();
			size--;
			return temp;
		}
		else {
			size--;
			return temp;
		}
	}
	boolean isEmpty() {
		if(size==0)return true;
		else return false;
	}
	
	public static void main(String[] args) {
		stackk<Character> stack=new stackk<Character>();
		Scanner input=new Scanner(System.in);
	
		Scanner sin=new Scanner(System.in);
		
		boolean run=true;
		String str1;
		int num;
		while(run) {
			num=sin.nextInt();
			switch(num) {
				case 1:
					str1=input.nextLine();
					for(int i=0; i<str1.length();i++) {
						stack.push(str1.charAt(i));
					}
					System.out.println(stack.size);
					break;
				case 2:
					System.out.println(stack.pop());
					break;
				case 3:
					System.out.println(stack.top());;
					break;
				default:
					run=false;
					break;
			}
		}
	}
}
