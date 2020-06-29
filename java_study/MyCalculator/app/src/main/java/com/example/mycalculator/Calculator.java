package com.example.mycalculator;

import android.util.Log;

public class Calculator {

    int arryleng;

    Calculator(int arryleng)
    {
        this.arryleng = arryleng;
    }


    public String[] calculatorForBracket(String[] expression, int arryleng)
    {

        for(int i = arryleng; i >= 0; i --)
        {
            if( expression[i].equals("("))
            {
                for(int j = i;  j < arryleng+1; j++)
                {
                    if( expression[j].equals(")"))
                    {
                        String[] e1 = new String[(j - i) - 1];
                        int n = 0;
                        for(int k = i+1; k < j; k++)
                        {
                            e1[n] = expression[k];
                            n++;
                        }
                        e1 = calculatorForLog(e1, e1.length);
                        e1 = calculatorForProdcut_Divide(e1, this.arryleng);
                        e1 = calculatorForPlus_Minus(e1, this.arryleng);

                        this.arryleng = arryleng - e1.length;
                        expression = moveIndexForBracket(expression, Double.parseDouble(e1[0]), i,j);

                        break;
                    }
                }


            }

        }

        return expression;
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

                expression = moveIndex(expression, i-1);
                arryleng -= 2;

                i--;
                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("^",b+"값 : "+ expression[b]);
                }
                continue;
            }

            if( expression[i].equals("log"))
            {
                //test[i] 뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
                expression[i] = Double.toString(log(Double.parseDouble(expression[i+1])));

                expression = moveIndexForlog(expression, i+1);
                arryleng -= 1;

                i--;
                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("log",b+"값 : " + expression[b]);
                }
                continue;
            }

            if( expression[i].equals("sqrt"))
            {
                //test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
                expression[i] = Double.toString(sqrt(Double.parseDouble(expression[i+1])));

                expression = moveIndexForlog(expression, i+1);
                arryleng -= 1;

                i--;
                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("sqrt",b+"값 : " + expression[b]);
                }
                continue;
            }

            if( expression[i].equals("EXP"))
            {
                //test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
                expression[i] = Double.toString(exp(Double.parseDouble(expression[i+1])));

                expression = moveIndexForlog(expression, i+1);
                arryleng -= 1;

                i--;
                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("exp",b+"값 : " + expression[b]);
                }
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
            if( expression[i].equals("x"))
            {
                //test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
                expression[i-1] = Double.toString(product(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

                expression = moveIndex(expression, i-1);
                arryleng -= 2;

                i--;

                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("x",b+"값 : " + expression[b]);
                }

            }

            if( expression[i].equals("/"))
            {
                //test[i] 앞뒤에 있는 값을 double형으로 변환 후 곱해서 다시 String형으로 변환해서 test[i-1]에 넣음.
                expression[i-1] = Double.toString(divide(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

                expression = moveIndex(expression, i-1);
                arryleng -= 2;

                i--;

                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("/",b+"값 : " + expression[b]);
                }

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

                expression = moveIndex(expression, i-1);
                arryleng -= 2;


                i--;

                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("+",b+"값 : " + expression[b]);
                }

            }

            if(expression[i].equals("-"))
            {
                expression[i-1] = Double.toString(minus(Double.parseDouble(expression[i-1]), Double.parseDouble(expression[i+1])));

                expression = moveIndex(expression, i-1);
                arryleng -= 2;

                i--;

                for(int b = 0; b < expression.length; b++)
                {
                    Log.i("-",b+"값 : "+ expression[b]);
                }

            }

        }


        this.arryleng = arryleng;
        return expression;
    }

    public double exp(double x)
    {
        double result = Math.round(Math.exp(x) * 10000) / 10000.0;
        return  result;
    }

    public double sqrt(double x)
    {
        double result = Math.round(Math.sqrt(x) * 100000) / 100000.0;
        return result;
    }


    public double log(double x)
    {
        double result = Math.round(Math.log10(x) * 100000) / 100000.0;
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
        double result = Math.round((x * y) * 10000) / 10000.0;
        return result;
    }



    public double divide (double x, double y)
    {
        double result = Math.round((x / y) * 10000) / 10000.0 ;
        return result;
    }



    public double minus(double x, double y)
    {
        double result = x - y;
        return result;
    }


    /*인덱스 계산용*/
    public String[] moveIndex(String[] expression, int index)
    {
        //System.out.println((index) + " 번째 값(move) : " +test[index]);

        for(int i  = index + 1; i < expression.length - 2; i++)
        {
            expression[i] = expression[i + 2];
        }
        expression[expression.length - 2] = null;
        expression[expression.length - 1] = null;

        return expression;
    }


    public String[] moveIndexForlog(String[] expression, int index)
    {
        for(int i = index; i < expression.length - 1; i++)
        {
            expression[i] = expression[i+1];
        }
        expression[expression.length - 1] = null;

        return expression;
    }

    public String[] moveIndexForBracket(String[] expression, double value, int left, int right)
    {

        expression[left] = Double.toString(value);
        left++;
        for(int i = right+1; i < expression.length; i++)
        {
            expression[left] = expression[i];
            left++;
        }
        for(int i = left; i < expression.length; i++)
        {
            expression[i] = "";
        }


        return  expression;
    }


}
