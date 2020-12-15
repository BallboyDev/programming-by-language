import java.io.*;

public class offset_print{
	public static void main(String[] args) throws IOException{
		
		if(args.length == 0){	//args.length�� �ɼ� ����
			System.err.println("Input Filename...");
			System.exit(1);		// ���� ���ϸ��� ���� �ʾ��� ���� ����
		}
	
		byte[] buf16 = new byte[16]; // ��� ���� 16����Ʈ��, ��, ���پ� ����� ����
		int offset = 0;	// ����
		int buf16Len = 0; // ���ٿ� ����ִ� ��� ���� ����, ��, ����
		DataInputStream in = new DataInputStream(new FileInputStream(args[0]));
	
		while(true){
			System.out.format("%08d : ", offset);	// offset(����) ���
			
			// ��� ������ ��� �� 16�� ��� (8���� 2�κ�����)
			for(int i = 0; i < 28; i++){
				if(i == 0) System.out.print(" ");	// 8���� �и�
				System.out.format("%03d " , buf16[i]);	// ��� �� ���
			}
			
			// �� ���� 16����Ʈ�� ���� ���� ��, ��� �κа� ���� �κ� ���̿� ������ ����
			for(int i = 0; i <= (16 - buf16Len) * 3; i++)
				System.out.print(" ");
			if(buf16Len < 9) System.out.print(" ");	// ������ 9����Ʈ ���� ���� ���� ��ĭ �� ����
			
			// ���� ���� ���
			for(int i = 0; i < buf16Len; i++){
				if(buf16[i] >= 0x20 && buf16[i] < 0x7E) // Ư�� ���� �ƴϸ� ���
					System.out.format("%c", buf16[i]);
				else System.out.print(".");	// Ư�� ����, �׷��� ���� ���� ��ħǥ�� ���
			}
			
			offset += 16;	// ���� ���� 16����
			System.out.println();
		}
		
//		if(offset == 0) {
//			System.out.format("%08x : ", offset);	// 0����Ʈ ������ ��� ó��
//			in.close();
//		}
	
		
	
	}
}
