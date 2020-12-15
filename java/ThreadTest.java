class WorkObject{ // 공유 객체 클래스
	public synchronized void methodA(){
		System.out.println("ThreadA의 methodA() 작업 실행");
		notify(); // 일시 정지 상태에 있는 ThreadB를 실행 대기 상태로 전환
		try{
			wait(); // ThreadA를 일시 정지 상태로 전환
		}
		catch(InterruptedException e){}
	}
	
	public synchronized void methodB(){
		System.out.println("ThreadB의 methodB() 작업 실행");
		notify(); // 일시 정지 상태에 있는 ThreadA를 실행 대기 상태로 전환
		try{
			wait(); // ThreadB를 일시 정지 상태로 전환
		}
		catch(InterruptedException e){}
	}
}

class ThreadA extends Thread{
	private WorkObject workObject;
	
	public ThreadA(WorkObject workObject){
		this.workObject = workObject; // 공유 객체 저장
	}
	
	@Override
	public void run(){
		for(int i=0;; i++){
			workObject.methodA(); // 공유 객체의 methodA() 호출
		}
	}
}

class ThreadB extends Thread{
	private WorkObject workObject;
	
	public ThreadB(WorkObject workObject){
		this.workObject = workObject; // 공유 객체 저장
	}
	
	@Override
	public void run(){
		for(int i=0;; i++){
			workObject.methodB(); // 공유 객체의 methodB() 호출
		}
	}
}

public class ThreadTest {
	public static void main(String args[]){
		WorkObject sharedObject = new WorkObject(); // 공유 객체 생성
		
		ThreadA threadA = new ThreadA(sharedObject);
		ThreadB threadB = new ThreadB(sharedObject);
		
		// start
		threadA.start();
		threadB.start();
	}
}
