class WorkObject{ // ���� ��ü Ŭ����
	public synchronized void methodA(){
		System.out.println("ThreadA�� methodA() �۾� ����");
		notify(); // �Ͻ� ���� ���¿� �ִ� ThreadB�� ���� ��� ���·� ��ȯ
		try{
			wait(); // ThreadA�� �Ͻ� ���� ���·� ��ȯ
		}
		catch(InterruptedException e){}
	}
	
	public synchronized void methodB(){
		System.out.println("ThreadB�� methodB() �۾� ����");
		notify(); // �Ͻ� ���� ���¿� �ִ� ThreadA�� ���� ��� ���·� ��ȯ
		try{
			wait(); // ThreadB�� �Ͻ� ���� ���·� ��ȯ
		}
		catch(InterruptedException e){}
	}
}

class ThreadA extends Thread{
	private WorkObject workObject;
	
	public ThreadA(WorkObject workObject){
		this.workObject = workObject; // ���� ��ü ����
	}
	
	@Override
	public void run(){
		for(int i=0;; i++){
			workObject.methodA(); // ���� ��ü�� methodA() ȣ��
		}
	}
}

class ThreadB extends Thread{
	private WorkObject workObject;
	
	public ThreadB(WorkObject workObject){
		this.workObject = workObject; // ���� ��ü ����
	}
	
	@Override
	public void run(){
		for(int i=0;; i++){
			workObject.methodB(); // ���� ��ü�� methodB() ȣ��
		}
	}
}

public class ThreadTest {
	public static void main(String args[]){
		WorkObject sharedObject = new WorkObject(); // ���� ��ü ����
		
		ThreadA threadA = new ThreadA(sharedObject);
		ThreadB threadB = new ThreadB(sharedObject);
		
		// start
		threadA.start();
		threadB.start();
	}
}
