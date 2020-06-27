package com.example.mycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    boolean isFirstInput = true;
    boolean isNumber = false;
    boolean islog = true;
    boolean isInNumber = false;// 입력 중인 숫자가 1개이면 false 2개이면 true;
    int resultNumber = 0;
    int Clickcnt = -1;

    //expression 배열에 식을 넣기 전처리를 위한 배열
    String[] before_chk = new String[20];
    String[] expression = null;




    TextView resultText;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        resultText = findViewById(R.id.result_text);

    }

    public void buttonClick(View view)
    {

        Button getButton = findViewById(view.getId());


        switch (view.getId())
        {
            case R.id.clear_button:
                isFirstInput = true;
                isNumber = false;
                islog = true;
                resultNumber = 0;
                Clickcnt = -1;
                before_chk = new String[20];

                resultText.setTextColor(0xff8A8A8A);
                resultText.setText(String.valueOf(resultNumber));

                break;


            case R.id.plus_button:

            case R.id.divide_button:

            case R.id.product_button:

            case R.id.minus_button:

            case R.id.pow_button:

                if((isFirstInput) || (!isNumber))
                {
                    Toast.makeText(getApplicationContext(),"숫자를 먼저 입력하셔야 합니다.", Toast.LENGTH_LONG).show();
                }else
                {
                    Clickcnt ++;
                    before_chk[Clickcnt] = getButton.getText().toString();
                    resultText.append(getButton.getText().toString());
                    isNumber = false;
                    islog = true;

                }

                break;


            //                    Log.i("array","숫자"+cal.expression[Clickcnt]+" 클릭 카운트 : " + Clickcnt + "다음 인덱스 값 : " + cal.expression[Clickcnt + 1] + "이전 인덱스 값 : " + cal.expression[Clickcnt - 1]);

            case R.id.equal_button :
                if(!isNumber)
                {
                    Toast.makeText(getApplicationContext(),"식을 완성해야합니다.", Toast.LENGTH_LONG).show();
                }else
                {
                    expression = new String[Clickcnt+1];
                    Log.i("AA", " 0번값 : " + expression[0] + " // 1번값 : " + expression[1]);
                    for(int j = 0; j < expression.length;j ++)
                    {
                        expression[j] = before_chk[j];
                        Log.i("bb", j+" 번값 : " + expression[j] );
                    }

                    //계산 함수가 있는 클래스 객체 생성 및 생성자로 arryleng를 넘김
                    Calculator cal = new Calculator(Clickcnt);
                    Log.i("cc", " 0번값 : " + expression[0] + " // 1번값 : " + expression[1]);

                    expression = cal.calculatorForLog(expression, Clickcnt);
                    expression = cal.calculatorForProdcut_Divide(expression, cal.arryleng);
                    expression = cal.calculatorForPlus_Minus(expression, cal.arryleng);
                    Log.i("dd", " 0번값 : " + expression[0] + " // 1번값 : " + expression[1]);
                    resultText.setText(expression[0]);


                    // 계산이 끝나면 결과값이 0번에 들어가고 다음 수식은 1번 인덱스부터 들어간다.
                    before_chk = new String[20];
                    before_chk[0] = expression[0];
                    Clickcnt = 0;

                    for(int b = 0; b < expression.length; b++)
                    {
                        Log.i("expression","배열 값" + expression[b]);
                        Log.i("before_chk","배열 값" + before_chk[b]);
                    }
                }

                break;


            case R.id.exp_button:

            case R.id.log_button:

            case R.id.sqrt_button:
                if(isFirstInput)
                {
                    Clickcnt++;
                    resultText.setTextColor(0xff000000);
                    resultText.setText(getButton.getText().toString());
                    before_chk[Clickcnt] = getButton.getText().toString();

                    isFirstInput = false;
                    islog = false;

                }else if(!islog)
                {
                    Toast.makeText(getApplicationContext(),"부호를 먼저 넣어야합니다.", Toast.LENGTH_LONG).show();
                }else if(islog)
                {
                    Clickcnt ++;
                    before_chk[Clickcnt] = getButton.getText().toString();
                    resultText.append(getButton.getText().toString());
                    islog = false;
                }

                    break;

//            case R.id.exp_button 이전 버전
/*
            case R.id.exp_button:
                if(isFirstInput)
                {
                    Clickcnt++;
                    resultText.setTextColor(0xff000000);
                    resultText.setText("e^");
                    before_chk[Clickcnt] = getButton.getText().toString();

                    isFirstInput = false;
                    islog = false;

                }else if(isNumber && !islog)//숫자받기
                {
                    Toast.makeText(getApplicationContext(),"부호를 먼저 넣어야합니다.", Toast.LENGTH_LONG).show();
                }else if(islog)
                {
                    Clickcnt ++;
                    before_chk[Clickcnt] = getButton.getText().toString();
                    resultText.append("e^");
                    //부호가 못들어가게, 숫자만 드가게
                    isNumber = false;
                    islog = false;

                }

                break;
*/
            case R.id.dot_button:
                if(isNumber && !islog)
                {
                    before_chk[Clickcnt] = before_chk[Clickcnt] + getButton.getText().toString();
                    resultText.append(getButton.getText().toString());
                    isNumber = false;
                    Clickcnt--;
                }
                break;

            //backSpace 구현실패
            //boolean으로 선언된거 전부를 int형 배열로 만들어서 before_chk에 입력될때 마다
            //int형 배열에 입력한 후 backSpace로 지울때 마다 확인해서 지금 숫자를 받아야되는지
            //연산자를 받아야되는지 구별
            /*
            case R.id.bs_button:
                if(isInNumber)// 입력 중인 숫자가 1개이면 false 2개이면 true;
                {
                    String getResultText = resultText.getText().toString();
                    String subString = getResultText.substring(0,getResultText.length() -1);
                    resultText.setText(subString);



                    //마지막껄 받아와서 정수로 형변환 시켜서 뒷 숫자 자르고 다시 넣기
                    before_chk[Clickcnt] = before_chk[Clickcnt].substring(0,Integer.parseInt(before_chk[Clickcnt]) - 1);
                    for(int b = 0; b < before_chk.length; b++)
                    {
                        Log.i("delete - - 1",b+"값 : " + before_chk[b]);
                    }

                }else if(!isInNumber)
                {
                    if(Clickcnt < 0)
                    {//첨부터 다시 시작
                        isFirstInput = true;
                        isNumber = false;
                        islog = true;
                        isInNumber = false; // 입력 중인 숫자가 1개이면 false 2개이면 true;
                        Clickcnt = -1;

                        resultText.setTextColor(0xff8A8A8A);
                        resultText.setText("0");

                    }else{
                        before_chk[Clickcnt] = "";
                        Clickcnt--;

                        String getResultText = resultText.getText().toString();
                        String subString = getResultText.substring(0,getResultText.length() -1);
                        resultText.setText(subString);

                    }


                    for(int b = 0; b < before_chk.length; b++)
                    {
                        Log.i("delete - - 2",b+"값 : " + before_chk[b] + " click 값 : " + Clickcnt);
                    }
                }

                break;
                */


                //0 ~ 9까지 숫자가 들어오면 실행
            case R.id.num_0_button:
            case R.id.num_1_button:
            case R.id.num_2_button:
            case R.id.num_3_button:
            case R.id.num_4_button:
            case R.id.num_5_button:
            case R.id.num_6_button:
            case R.id.num_7_button:
            case R.id.num_8_button:
            case R.id.num_9_button:
                if(!isNumber)
                {
                    isNumber = true;
                    islog = false;
                    Clickcnt ++;
                }

                if(isFirstInput)
                {
                    Log.i("array",getButton.getText().toString());
                    resultText.setTextColor(0xff000000);
                    //resultText.setText(문자열)는 resultText에 텍스트를 추가 하는데 기존에 있던 텍스트는 모두 지우고 새로 추가
                    resultText.setText(getButton.getText().toString());
                    before_chk[Clickcnt] = getButton.getText().toString();

                    isFirstInput = false;
                    isNumber = true;
                }else
                {
                    //append 는 문자열을 지우지 않고 그대로 추가
                    resultText.append(getButton.getText().toString());
                    Log.i("값", " Click  : " +Clickcnt + " before : " + before_chk[Clickcnt]);
                    if(before_chk[Clickcnt] == null)
                    {
                        before_chk[Clickcnt] = getButton.getText().toString();

                    }else
                    {
                        before_chk[Clickcnt] = before_chk[Clickcnt] + getButton.getText().toString();

                    }
//                    Log.i("array","누른거"+getButton.getText().toString());
//                    Log.i("array","숫자"+cal.expression[Clickcnt]+" 클릭 카운트 : " + Clickcnt + "다음 인덱스 값 : " + cal.expression[Clickcnt + 1] + "이전 인덱스 값 : " + cal.expression[Clickcnt - 1]);
                }

                break;

            default:
                Toast.makeText(getApplicationContext(),getButton.getText().toString() + " 버튼이 클릭 되었습니다.", Toast.LENGTH_LONG).show();
                break;
        }
    }
}