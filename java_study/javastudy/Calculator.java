package javastudy;

public class Calculator {
	
	int arryleng;
	
	Calculator(int arryleng)
	{
		this.arryleng = arryleng;
	}
	
	//����, log, ��Ʈ ���
	public String[] calculatorForLog(String[] expression, int arryleng)
	{
		for(int i = 0; i < arryleng; i ++)
 		{
 			if( expression[i].equals("^"))
			{
 				//test[i] �յڿ� �ִ� ���� double������ ��ȯ �� ���ؼ� �ٽ� String������ ��ȯ�ؼ� test[i-1]�� ����.
 				expression[i-1] = Double.toString(pow(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
 				//System.out.println("�迭 ũ�� : " + expression.length);
 				expression = moveIndex(expression, i-1);
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
 				continue;
			}
 			
 			if( expression[i].equals("log"))
			{
 				//test[i] �յڿ� �ִ� ���� double������ ��ȯ �� ���ؼ� �ٽ� String������ ��ȯ�ؼ� test[i-1]�� ����.
 				expression[i] = Double.toString(log(Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
 				//System.out.println("�迭 ũ�� : " + expression.length);
 				expression = moveIndexForlog(expression, i+1);
				arryleng -= 1;
		 		/*
				for(int j = 0; j < expression.length;j ++)
		 		{
		 			System.out.println(expression[j]);
		 		}
		 		*/
		 		//System.out.println("i�� : " + i);
		 		//System.out.println("arryleng ��  : " + arryleng);
		 		i--;
 				continue;
			}
 			
 			if( expression[i].equals("sqrt"))
			{
 				//test[i] �յڿ� �ִ� ���� double������ ��ȯ �� ���ؼ� �ٽ� String������ ��ȯ�ؼ� test[i-1]�� ����.
 				expression[i] = Double.toString(sqrt(Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
 				//System.out.println("�迭 ũ�� : " + expression.length);
 				expression = moveIndexForlog(expression, i+1);
				arryleng -= 1;
		 		/*
				for(int j = 0; j < expression.length;j ++)
		 		{
		 			System.out.println(expression[j]);
		 		}
		 		*/
		 		//System.out.println("i�� : " + i);
		 		//System.out.println("arryleng ��  : " + arryleng);
		 		i--;
 				continue;
			}
 			

 			
 		}
		this.arryleng = arryleng;
		return expression;
	}
	
	
	public String[] calculatorForProdcut_Divide(String[] expression, int arryleng)
	{
		
		for(int i = 1; i < arryleng; i ++)
 		{
 			if( expression[i].equals("*"))
			{
 				//test[i] �յڿ� �ִ� ���� double������ ��ȯ �� ���ؼ� �ٽ� String������ ��ȯ�ؼ� test[i-1]�� ����.
 				expression[i-1] = Double.toString(product(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
 				//System.out.println("�迭 ũ�� : " + expression.length);
 				expression = moveIndex(expression, i-1);
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
 				expression[i-1] = Double.toString(divide(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
 				
 				expression = moveIndex(expression, i-1);
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
		
		
		this.arryleng = arryleng;
		return expression;
	}
	
	
	public String[] calculatorForPlus_Minus(String[] expression, int arryleng)
	{
		
		for(int i = 0; i < arryleng; i ++)
 		{
 			if(expression[i].equals("+"))
 			{
 				expression[i-1] = Double.toString(plus(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
 					
 				expression = moveIndex(expression, i-1);
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
 				expression[i-1] = Double.toString(minus(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

 				//System.out.println((i-1) + " ��° �� : " +expression[i-1]);
 					
 				expression = moveIndex(expression, i-1);
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
		
		
		this.arryleng = arryleng;
		return expression;
	}
	
	
	public double sqrt(double x)
	{
		double result = Math.sqrt(x);
		return result;
	}
	
	
	public double log(double x)
	{
		double result = Math.log10(x);
		return result;
	}
	
	
	public double pow(double x, double y)
	{
		double result = Math.pow(x, y);
		return result;
	}
	
	
	public double plus (double x, double y)
	{
		double result = x + y;
		return result;
	}
	
	
	
	public double product (double x, double y)
	{
		double result = x * y;
		return result;
	}
	
	
	
	public double divide (double x, double y)
	{
		double result = x / y;
		return result;
	}
	
	
	
	public double minus(double x, double y)
	{
		double result = x - y;
		return result;
	}

	
	
	/*�ε��� ����*/
	public String[] moveIndex(String[] ary, int index)
	{
		//System.out.println((index) + " ��° ��(move) : " +test[index]);

		for(int i  = index + 1; i < ary.length - 2; i++)
		{
			ary[i] = ary[i + 2];
		}
		ary[ary.length - 2] = null;
		ary[ary.length - 1] = null;
	
		return ary;
	}
	

	public String[] moveIndexForlog(String[] ary, int index)
	{
		for(int i = index; i < ary.length - 2; i++)
		{
			ary[i] = ary[i+1];
		}
		ary[ary.length - 1] = null;
		
		return ary;
	}
}
