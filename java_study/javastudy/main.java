package javastudy;

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

			//��� �Լ��� �ִ� Ŭ���� ��ü ���� �� �����ڷ� arryleng�� �ѱ�
			Calculator cal = new Calculator(arryleng);
			
	 		//calculatorŬ�������� ��� �� �ε��� ������ ���� 
	 		cal.arryleng = arryleng;
	 		
	 		//����, log, ��Ʈ ���
	 		expression = cal.calculatorForLog(expression, cal.arryleng);

	 		
	 		//������ ������ ���� ó��
	 		expression = cal.calculatorForProdcut_Divide(expression, cal.arryleng);
	 		
	 		 		
	 		//���� ���� ó��
	 		expression = cal.calculatorForPlus_Minus(expression, cal.arryleng);
	 		
	 		
	 		
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
