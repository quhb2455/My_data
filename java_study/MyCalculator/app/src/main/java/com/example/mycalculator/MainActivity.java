package com.example.mycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    boolean isFirstInput = true;
    int resultNumber = 0;
    char operator = '+';

    TextView resultText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        resultText = findViewById(R.id.result_text);
    }

    public void buttonClick(View view)
    {
        if(view.getId() == R.id.clear_button)
        {
            isFirstInput = true;
            resultNumber = 0;
            operator = '+';
            resultText.setTextColor(0xff8A8A8A);
            resultText.setText(String.valueOf(resultNumber));
        }

        if(view.getId() == R.id.num_1_button)
        {
            if(isFirstInput == true)
            {
                resultText.setTextColor(0xff000000);
                //resultText.setText(문자열)는 resultText에 텍스트를 추가 하는데 기존에 있던 텍스트는 모두 지우고 새로 추가
                resultText.setText("1");
                isFirstInput = false;
            }else
            {
                resultText.setTextColor(0xff000000);
                //resultText.setText(문자열)는 resultText에 텍스트를 추가 하는데 기존에 있던 텍스트는 모두 지우고 새로 추가
                resultText.append("1");
            }

        }
        else
        {

        }
    }
}