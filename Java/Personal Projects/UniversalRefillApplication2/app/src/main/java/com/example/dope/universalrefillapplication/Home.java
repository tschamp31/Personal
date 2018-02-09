package com.example.dope.universalrefillapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.content.Intent;


public class Home extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        /*Initiates activity swap and button for log in*/
        final Button loginButton = findViewById(R.id.logInButton);
        final Intent gotoPTProfile = new Intent(this, ptProfile.class);

        /*Initiates activity swap and button for sign up*/
        final Intent startSignUp = new Intent(this, signUp.class);
        final Button signupButton = findViewById(R.id.signUpButton);

        loginButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                startActivityForResult(gotoPTProfile, 0);
            }
        });

        signupButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                startActivityForResult(startSignUp, 0);
            }
        });
    }
}
