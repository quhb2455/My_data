package javastudy;

public class Calculator {
	
	int arryleng;
	
	Calculator(int arryleng)
	{
		this.arryleng = arryleng;
	}
	
	//제곱, log, 루트 계산
	public String[] calculatorForLog(String[] expression, int arryleng)
	{
		for(int i = 0; i < arryleng; i ++)
 		{
 			if( expression[i].equals("^"))
			{
 				//test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
 				expression[i-1] = Double.toString(pow(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " 번째 값 : " +expression[i-1]);
 				//System.out.println("배열 크기 : " + expression.length);
 				expression = moveIndex(expression, i-1);
				arryleng -= 2;
		 		/*
				for(int j = 0; j < expression.length;j ++)
		 		{
		 			System.out.println(expression[j]);
		 		}
		 		*/
		 		//System.out.println("i값 : " + i);
		 		//System.out.println("arryleng 값  : " + arryleng);
		 		i--;
 				continue;
			}
 			
 			if( expression[i].equals("log"))
			{
 				//test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
 				expression[i] = Double.toString(log(Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " 번째 값 : " +expression[i-1]);
 				//System.out.println("배열 크기 : " + expression.length);
 				expression = moveIndexForlog(expression, i+1);
				arryleng -= 1;
		 		/*
				for(int j = 0; j < expression.length;j ++)
		 		{
		 			System.out.println(expression[j]);
		 		}
		 		*/
		 		//System.out.println("i값 : " + i);
		 		//System.out.println("arryleng 값  : " + arryleng);
		 		i--;
 				continue;
			}
 			
 			if( expression[i].equals("sqrt"))
			{
 				//test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
 				expression[i] = Double.toString(sqrt(Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " 번째 값 : " +expression[i-1]);
 				//System.out.println("배열 크기 : " + expression.length);
 				expression = moveIndexForlog(expression, i+1);
				arryleng -= 1;
		 		/*
				for(int j = 0; j < expression.length;j ++)
		 		{
		 			System.out.println(expression[j]);
		 		}
		 		*/
		 		//System.out.println("i값 : " + i);
		 		//System.out.println("arryleng 값  : " + arryleng);
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
 				//test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
 				expression[i-1] = Double.toString(product(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));
 				
 				//System.out.println((i-1) + " 번째 값 : " +expression[i-1]);
 				//System.out.println("배열 크기 : " + expression.length);
 				expression = moveIndex(expression, i-1);
				arryleng -= 2;
		 		/*
				for(int j = 0; j < expression.length;j ++)
		 		{
		 			System.out.println(expression[j]);
		 		}
		 		*/
		 		//System.out.println("i값 : " + i);
		 		//System.out.println("arryleng 값  : " + arryleng);
		 		i--;
 				//continue;
			}
 			
 			if( expression[i].equals("/"))
			{
 				//test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
 				expression[i-1] = Double.toString(divide(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

 				//System.out.println((i-1) + " 번째 값 : " +expression[i-1]);
 				
 				expression = moveIndex(expression, i-1);
				arryleng -= 2;
				
				/*
				for(int j = 0; j < expression.length;j ++)
		 		{
		 			System.out.println(expression[j]);
		 		}
		 		*/
				//System.out.println("i값 : " + i);
		 		//System.out.println("arryleng 값  : " + arryleng);
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

 				//System.out.println((i-1) + " 번째 값 : " +expression[i-1]);
 					
 				expression = moveIndex(expression, i-1);
 				arryleng -= 2;
 				
 				/*
 				for(int j = 0; j < expression.length;j ++)
 		 		{
 		 			System.out.println(expression[j]);
 		 		}
 				System.out.println("i값 : " + i);
 		 		System.out.println("arryleng 값  : " + arryleng);
 		 		*/
 		 		i--;

 			}
 			
 			if(expression[i].equals("-"))
 			{
 				expression[i-1] = Double.toString(minus(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

 				//System.out.println((i-1) + " 번째 값 : " +expression[i-1]);
 					
 				expression = moveIndex(expression, i-1);
 				arryleng -= 2;
 				/*
 				for(int j = 0; j < expression.length;j ++)
 		 		{
 		 			System.out.println(expression[j]);
 		 		}
 				System.out.println("i값 : " + i);
 		 		System.out.println("arryleng 값  : " + arryleng);
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

	
	
	/*인덱스 계산용*/
	public String[] moveIndex(String[] ary, int index)
	{
		//System.out.println((index) + " 번째 값(move) : " +test[index]);

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
