package com.example.dope.universalrefillapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

/**
 * Created by Dope on 1/12/2018.
 */

public class ptProfile extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ptprofile);

        final Intent gotoRxInsuranceInformation = new Intent(this, insurance.class);
        final Button rxInsuranceButton = findViewById(R.id.insuranceButton);

        rxInsuranceButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                startActivityForResult(gotoRxInsuranceInformation, 0);
            }
        });
    }

}
