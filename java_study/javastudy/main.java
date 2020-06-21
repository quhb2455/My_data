package javastudy;

import java.util.*;


public class main {
	
	public static void main(String[] args) {
		
		// TODO Auto-generated method stub

		//expression 배열에 식을 넣기 전처리를 위한 배열
		String[] before_chk= new String[20];
		//식이 들어갈 배열
		String[] expression = null;
		//before_chk의 배열길이를 확인하고  expression배열에 복사 및 정의를 위한 변수
		int arryleng = 0;
		//입력식 계산 완료 후 더 계산 할려는지 묻기 위한 변수
		String chkMore;
		
		//scanner로 입력는 객체 생성.
		Scanner scanner = new Scanner(System.in);
		
		
		while(true)
		{
			
			System.out.println("연산자 포함 20개 입력");
			System.out.println("입력 시 => 숫자입력(enter) >> 연산자입력(enter) ... >> =입력(enter)");
			
	 		for(arryleng = 0; arryleng < 20; arryleng ++)
	 		{
	 			before_chk[arryleng] = scanner.nextLine();
	 			//System.out.println(before_chk[i]);

	 			if( before_chk[arryleng].equals("="))
				{
					break;
				}
				
	 		}
	 		
	 		//arryleng ++ 를 해줌으로써 '='연산자까지 포함 시켜줌
	 		//'='연산자를 포함 시키는 길이 만큼 expression배열을 정의
	 		//반복문을 통해서 before_chk -> expression으로 값 복사
	 		arryleng++;
	 		expression = new String[arryleng];
	 		for(int j = 0; j < expression.length;j ++)
	 		{
	 			expression[j] = before_chk[j];
	 			System.out.print(expression[j]);
	 		}

			//계산 함수가 있는 클래스 객체 생성 및 생성자로 arryleng를 넘김
			Calculator cal = new Calculator(arryleng);
			
	 		//calculator클래스에서 계산 시 인덱스 조절을 위해 
	 		cal.arryleng = arryleng;
	 		
	 		//제곱, log, 루트 계산
	 		expression = cal.calculatorForLog(expression, cal.arryleng);

	 		
	 		//곱셈과 나누셈 먼저 처리
	 		expression = cal.calculatorForProdcut_Divide(expression, cal.arryleng);
	 		
	 		 		
	 		//덧셈 뺄셈 처리
	 		expression = cal.calculatorForPlus_Minus(expression, cal.arryleng);
	 		
	 		
	 		
	 		//System.out.println("입력 식 정답 : " + expression[0]);
	 		System.out.println(expression[0]);
	 		System.out.println("===========================");
	 		System.out.println("계속 계산 할래? (y/n) ");
	 		chkMore = scanner.nextLine();
	 		
	 		if(chkMore.equals("n"))
	 		{
	 			System.out.println("종료");
	 			break;
	 		}
			


		}
		
		
	}

}
