package javastudy;

import java.io.Console;
import java.util.*;


public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//expression �迭�� ���� �ֱ� ��ó���� ���� �迭
		String[] before_chk= new String[20];
		//���� �� �迭
		String[] expression = null;
		//before_chk�� �迭���̸� Ȯ���ϰ�  expression�迭�� ���� �� ���Ǹ� ���� ����
		int arryleng = 0;
		//�Է½� ��� �Ϸ� �� �� ��� �ҷ����� ���� ���� ����
		String chkMore;
		//scanner�� �Է´� ��ü ����.
		Scanner scanner = new Scanner(System.in);
		
		//��� �Լ��� �ִ� Ŭ���� ��ü ����.
		Calculator cal = new Calculator();
		
		while(true)
		{
			
			System.out.println("������ ���� 20�� �Է�");
			System.out.println("�Է� �� => �����Է�(enter) >> �������Է�(enter) ... >> =�Է�(enter)");
			
	 		for(arryleng = 0; arryleng < 20; arryleng ++)
	 		{
	 			before_chk[arryleng] = scanner.nextLine();
	 			//System.out.println(before_chk[i]);

	 			if( before_chk[arryleng].equals("="))
				{
					break;
				}
				
	 		}
	 		
	 		//arryleng ++ �� �������ν� '='�����ڱ��� ���� ������
	 		//'='�����ڸ� ���� ��Ű�� ���� ��ŭ expression�迭�� ����
	 		//�ݺ����� ���ؼ� before_chk -> expression���� �� ����
	 		arryleng++;
	 		expression = new String[arryleng];
	 		for(int j = 0; j < expression.length;j ++)
	 		{
	 			expression[j] = before_chk[j];
	 			System.out.print(expression[j]);
	 		}
	 		
	 		
	 		//������ ������ ���� ó��
	 		for(int i = 1; i < arryleng; i ++)
	 		{
	 			if( expression[i].equals("*"))
				{
	 				//test[i] �յڿ� �ִ� ���� double������ ��ȯ �� ���ؼ� �ٽ� String������ ��ȯ�ؼ� test[i-1]�� ����.
	 				expression[i-1] = Double.toString(cal.product(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));
	 				
	 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
	 				//System.out.println("�迭 ũ�� : " + expression.length);
	 				expression = cal.moveIndex(expression, i-1);
					arryleng -= 2;
			 		/*
					for(int j = 0; j < expression.length;j ++)
			 		{
			 			System.out.println(expression[j]);
			 		}
			 		*/
			 		//System.out.println("i�� : " + i);
			 		//System.out.println("arryleng ��  : " + arryleng);
			 		i--;
	 				//continue;
				}
	 			
	 			if( expression[i].equals("/"))
				{
	 				//test[i] �յڿ� �ִ� ���� double������ ��ȯ �� ���ؼ� �ٽ� String������ ��ȯ�ؼ� test[i-1]�� ����.
	 				expression[i-1] = Double.toString(cal.divide(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

	 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
	 				
	 				expression = cal.moveIndex(expression, i-1);
					arryleng -= 2;
					
					/*
					for(int j = 0; j < expression.length;j ++)
			 		{
			 			System.out.println(expression[j]);
			 		}
			 		*/
					//System.out.println("i�� : " + i);
			 		//System.out.println("arryleng ��  : " + arryleng);
			 		i--;
					//continue;
				}
	 			
	 		}
	 		
	 		
	 		//���� ���� ó��
	 		for(int i = 0; i < arryleng; i ++)
	 		{
	 			if(expression[i].equals("+"))
	 			{
	 				expression[i-1] = Double.toString(cal.plus(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

	 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
	 					
	 				expression = cal.moveIndex(expression, i-1);
	 				arryleng -= 2;
	 				
	 				/*
	 				for(int j = 0; j < expression.length;j ++)
	 		 		{
	 		 			System.out.println(expression[j]);
	 		 		}
	 				System.out.println("i�� : " + i);
	 		 		System.out.println("arryleng ��  : " + arryleng);
	 		 		*/
	 		 		i--;

	 			}
	 			
	 			if(expression[i].equals("-"))
	 			{
	 				expression[i-1] = Double.toString(cal.minus(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

	 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
	 					
	 				expression = cal.moveIndex(expression, i-1);
	 				arryleng -= 2;
	 				/*
	 				for(int j = 0; j < expression.length;j ++)
	 		 		{
	 		 			System.out.println(expression[j]);
	 		 		}
	 				System.out.println("i�� : " + i);
	 		 		System.out.println("arryleng ��  : " + arryleng);
	 		 		*/
	 		 		i--;

	 			}
	 			
	 		}
	 		
	 		//System.out.println("�Է� �� ���� : " + expression[0]);
	 		System.out.println(expression[0]);
	 		System.out.println("===========================");
	 		System.out.println("��� ��� �ҷ�? (y/n) ");
	 		chkMore = scanner.nextLine();
	 		
	 		if(chkMore.equals("n"))
	 		{
	 			System.out.println("����");
	 			break;
	 		}
			


		}
	}

}
