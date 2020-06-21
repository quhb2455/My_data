package javastudy;

public class Calculator {
	
	public String[] moveIndex(String[] test, int index)
	{
		//test[index - 1] = test[index];
		//System.out.println((index) + " ¹øÂ° °ª(move) : " +test[index]);

		for(int i  = index + 1; i < test.length - 2; i++)
		{
			test[i] = test[i + 2];
		}
		test[test.length - 2] = null;
		test[test.length - 1] = null;
	
		return test;
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

}
