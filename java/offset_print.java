import java.io.*;

public class offset_print{
	public static void main(String[] args) throws IOException{
		
		if(args.length == 0){	//args.length는 옵션 개수
			System.err.println("Input Filename...");
			System.exit(1);		// 읽은 파일명을 주지 않았을 때는 종료
		}
	
		byte[] buf16 = new byte[16]; // 헥사 값이 16바이트씩, 즉, 한줄씩 저장될 버퍼
		int offset = 0;	// 번지
		int buf16Len = 0; // 한줄에 들어있는 헥사 값의 개수, 즉, 길이
		DataInputStream in = new DataInputStream(new FileInputStream(args[0]));
	
		while(true){
			System.out.format("%08d : ", offset);	// offset(번지) 출력
			
			// 헥사 구역의 헥사 값 16개 출력 (8개씩 2부분으로)
			for(int i = 0; i < 28; i++){
				if(i == 0) System.out.print(" ");	// 8개씩 분리
				System.out.format("%03d " , buf16[i]);	// 헥사 값 출력
			}
			
			// 한 줄이 16바이트가 되지 않을 때, 헥사 부분과 문자 부분 사이에 공백을 삽입
			for(int i = 0; i <= (16 - buf16Len) * 3; i++)
				System.out.print(" ");
			if(buf16Len < 9) System.out.print(" ");	// 한줄이 9바이트 보다 적을 때는 한칸 더 삽입
			
			// 문자 구역 출력
			for(int i = 0; i < buf16Len; i++){
				if(buf16[i] >= 0x20 && buf16[i] < 0x7E) // 특수 문자 아니면 출력
					System.out.format("%c", buf16[i]);
				else System.out.print(".");	// 특수 문자, 그래픽 문자 등은 마침표로 출력
			}
			
			offset += 16;	// 번지 값을 16증가
			System.out.println();
		}
		
//		if(offset == 0) {
//			System.out.format("%08x : ", offset);	// 0바이트 파일일 경우 처리
//			in.close();
//		}
	
		
	
	}
}
