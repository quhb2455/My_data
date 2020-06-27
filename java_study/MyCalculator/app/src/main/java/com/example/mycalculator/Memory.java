package com.example.mycalculator;

import android.util.Log;
import android.content.Context;
import android.widget.Toast;

import java.io.*;

public class Memory {



    String[] MemoryExpression = new String[20];

    public void InputMemory(String[] expression, String answer, int arryleng)
    {

        for(int i = 0; i < arryleng; i++)
        {
            this.MemoryExpression[i] = expression[i];
        }
        MemoryExpression[arryleng] = "=";
        MemoryExpression[arryleng + 1] = answer;

        for(int b = 0; b < arryleng+2; b++)
        {
            Log.i("aaaaaaaaaaaaaaaaaa","배열 값" + expression[b]);
        }

    }



}
